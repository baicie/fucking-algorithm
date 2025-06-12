import { transformFromAstSync } from "@babel/core";
import { parse } from "@babel/parser";
import fs from "node:fs";
import path from "node:path";
import autoTrackPlugin from "./plugin/auto-track-plugin.js";

const sourceCode = fs.readFileSync("./sourceCode.js", {
  encoding: "utf-8",
});

const ast = parse(sourceCode, {
  sourceType: "unambiguous",
});

const { code } = transformFromAstSync(ast, sourceCode, {
  plugins: [
    [
      autoTrackPlugin,
      {
        trackerPath: "tracker",
      },
    ],
  ],
});

console.log(code);
