import { transformFromAstAsync } from "@babel/core";
import parser from "@babel/parser";
import forDirectionLintPlugin from "./plugin/for-direction-lint.js";

const sourceCode = `
for (var i = 0; i < 10; i++) {
}

for (var i = 10; i >= 0; i--) {
}
for (var i = 0; i < 10; i--) {
}

for (var i = 10; i >= 0; i++) {
}
`;

const ast = parser.parse(sourceCode, {
  sourceType: "unambiguous",
});

const { code } = await transformFromAstAsync(ast, sourceCode, {
  plugins: [forDirectionLintPlugin],
  filename: "input.js",
});

console.log(code);
