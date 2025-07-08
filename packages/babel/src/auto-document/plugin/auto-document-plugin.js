const { declare } = require("@babel/helper-plugin-utils");
const doctrine = require("doctrine");
const fse = require("fs-extra");
const renderer = require("./renderer");
const path = require("path");

function resolveType(tsType) {
  const typeAnnotation = tsType.typeAnnotation;
  if (!typeAnnotation) {
    return;
  }
  switch (typeAnnotation.type) {
    case "TSStringKeyword":
      return "string";
    case "TSNumberKeyword":
      return "number";
    case "TSBooleanKeyword":
      return "boolean";
  }
}

function parseCommoent(comment) {
  if (!comment) return;
  return doctrine.parse(comment, {
    unwrap: true,
  });
}

function generate(docs, format = "json") {
  if (format === "markdown") {
    return {
      ext: ".md",
      content: renderer.markdown(docs),
    };
  } else if (format === "html") {
    return {
      ext: "html",
      content: renderer.html(docs),
    };
  } else {
    return {
      ext: "json",
      content: renderer.json(docs),
    };
  }
}

const autoDocumentPlugin = declare((api, options) => {
  api.assertVersion(7);

  return {
    pre(file) {
      file.set("docs", []);
    },
    visitor: {
      FunctionDeclaration(path, state) {
        const docs = state.file.get("docs");
        docs.push({
          type: "function",
          name: path.get("id").toString(),
          params: path.get("params").map((param) => {
            return {
              name: param.toString(),
              type: resolveType(param.getTypeAnnotation()),
            };
          }),
          return: resolveType(path.get("returnType").getTypeAnnotation()),
          doc: path.node.leadingComments && path.node.leadingComments[0].value,
        });
        state.file.set("docs", docs);
      },
      ClassDeclaration(path, state) {
        const docs = state.file.get("docs");
        const classInfo = {
          type: "class",
          name: path.get("id").toString(),
          constructorInfo: {},
          methods: [],
          propertiesInfo: [],
        };
        if (path.node.leadingComments) {
          classInfo.doc = parseCommoent(path.node.leadingComments[0].value);
        }

        path.traverse({
          ClassProperty(path) {
            classInfo.propertiesInfo.push({
              name: path.get("key").toString(),
              type: resolveType(path.getTypeAnnotation()),
              doc: [path.node.leadingComments, path.node.trailingComments]
                .filter(Boolean)
                .map((comment) => {
                  return parseCommoent(comment.value);
                })
                .filter(Boolean),
            });
          },
          ClassMethod(path) {
            if (path.node.kind === "constructor") {
              classInfo.constructorInfo = {
                params: path.get("params").map((paramPath) => {
                  return {
                    name: paramPath.toString(),
                    type: resolveType(paramPath.getTypeAnnotation()),
                    doc: parseCommoent(path.node.leadingComments[0].value),
                  };
                }),
              };
            } else {
              classInfo.methods.push({
                name: path.get("key").toString(),
                doc: parseCommoent(path.node.leadingComments[0].value),
                params: path.get("params").map((param) => {
                  return {
                    name: param.toString(),
                    type: resolveType(param.getTypeAnnotation()),
                  };
                }),
                return: resolveType(path.getTypeAnnotation()),
              });
            }
          },
        });

        docs.push(classInfo);
        state.file.set("docs", docs);
      },
    },
    post(file) {
      const docs = file.get("docs");
      console.log(docs);
      const res = generate(docs, options.format);
      fse.ensureDirSync(options.outputDir);
      fse.writeFileSync(
        path.join(options.outputDir, "docs" + res.ext),
        res.content
      );
    },
  };
});

module.exports = autoDocumentPlugin;
