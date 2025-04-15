const sourceCode = `
    console.log(1);

    function func() {
        console.info(2);
    }

    export default class Clazz {
        say() {
            console.debug(3);
        }
        render() {
            return <div>{console.error(4)}</div>
        }
    }
`;

import { parse, traverse, transformFromAstSync, template } from "@babel/core";
import * as t from "@babel/types";
const ast = parse(sourceCode, {
  // 根据代码类型，选择合适的解析器
  sourceType: "unambiguous",
  plugins: ["@babel/plugin-syntax-jsx"],
})!;

const targetCalleeNames = ["log", "info", "debug", "error"].map(
  (item) => `console.${item}`
);

traverse(ast, {
  CallExpression(path, state) {
    if (path.node.isNew) {
      return;
    }
    const calleeName = path.get("callee").toString();
    if (targetCalleeNames.includes(calleeName)) {
      const { line, column } = path.node.loc?.start || {};
      const newNode = template.expression(
        `console.log("filename: (${line}, ${column})")`
      )();
      (newNode as any).isNew = true;
      if (path.findParent((path) => path.isJSXElement())) {
        path.replaceWith(t.arrayExpression([newNode as any, path.node]));
        path.skip();
      } else {
        path.insertBefore(newNode as any);
      }
    }
  },
});

const { code, map } = transformFromAstSync(ast, sourceCode)!;
console.log(code);
