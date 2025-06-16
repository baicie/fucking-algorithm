import { transformFromAstSync } from "@babel/core";
import { parse } from "@babel/parser";
import autoI18nPlugin from "./i18n.mjs";
import { readFileSync } from "fs";
import { join, resolve } from "path";
import { fileURLToPath } from "node:url";
import path from "node:path";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const sourceCode = readFileSync(join(__dirname, "./sourceCode.js"), {
  encoding: "utf-8",
});

const ast = parse(sourceCode, {
  sourceType: "unambiguous",
  plugins: ["jsx"],
});

const { code } = transformFromAstSync(ast, sourceCode, {
  plugins: [
    [
      autoI18nPlugin,
      {
        outputDir: resolve(__dirname, "./output"),
      },
    ],
  ],
});

console.log(code);
