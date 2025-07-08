import { transformFromAstSync } from "@babel/core";
import parser from "@babel/parser";
import eqLintPlugin from "./plugin/eq-lint.js";

const sourceCode = `
a == b
foo == true
bananas != 1
value == undefined
typeof foo == 'undefined'
'hello' != 'world'
0 == 0
true == true
`;

const ast = parser.parse(sourceCode, {
  sourceType: "unambiguous",
  comments: true,
});

const { code } = transformFromAstSync(ast, sourceCode, {
  plugins: [
    [
      eqLintPlugin,
      {
        fix: true,
      },
    ],
  ],
  comments: true,
});

console.log(code);
