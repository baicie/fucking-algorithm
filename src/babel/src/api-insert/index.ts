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

import { parse, traverse, transformFromAstSync } from "@babel/core";
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
    // if (
    //   t.isMemberExpression(path.node.callee) &&
    //   t.isIdentifier(path.node.callee.object) &&
    //   path.node.callee.object.name === "console" &&
    //   t.isIdentifier(path.node.callee.property) &&
    //   ["log", "info", "debug", "error"].includes(path.node.callee.property.name)
    // ) {
    //   const { line, column } = path.node.loc?.start || {};
    //   path.node.arguments.unshift(
    //     t.stringLiteral(`filename: (${line}, ${column})`)
    //   );
    // }
    const calleeName = path.get("callee").toString();
    if (targetCalleeNames.includes(calleeName)) {
      const { line, column } = path.node.loc?.start || {};
      path.node.arguments.unshift(
        t.stringLiteral(`filename: (${line}, ${column})`)
      );
    }
  },
});

const { code, map } = transformFromAstSync(ast, sourceCode)!;
console.log(code);
