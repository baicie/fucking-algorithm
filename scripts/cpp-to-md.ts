import { globSync } from "fast-glob";
import fs from "node:fs";
import path from "node:path";
import fse from "fs-extra";

const rootPath = path.resolve(__dirname, "..");
const vitePressDocPath = path.resolve(rootPath, "docs", "algorithm");
const sliderPath = path.resolve(
  rootPath,
  "docs",
  ".vitepress",
  "config",
  "sidebar.ts"
);
const algorithmMDPath = path.resolve(rootPath, "docs", "algorithm.md");

const files = globSync("../src/*.cpp", {
  cwd: __dirname,
  onlyFiles: true,
  absolute: true,
});

async function main() {
  // empty
  fse.emptyDirSync(vitePressDocPath);
  //   cp indexmd
  fse.copyFileSync(
    algorithmMDPath,
    path.resolve(vitePressDocPath, "algorithm.md")
  );
  let sidebar = `
    export default [
  `;
  for (const file of files) {
    const fileName = path.basename(file, path.extname(file));
    const content = fs.readFileSync(file, { encoding: "utf-8" });
    const newContent = `\`\`\` cpp
        ${content}
    \`\`\`
    `;
    const tagetPath = `${path.resolve(vitePressDocPath, fileName)}.md`;
    fs.writeFileSync(tagetPath, newContent, { encoding: "utf-8" });
    sidebar += `{text: "${path.basename(
      fileName
    )}", link: "${encodeURIComponent(fileName)}"},`;
  }
  sidebar += "]";
  fs.writeFileSync(sliderPath, sidebar, { encoding: "utf-8" });
}

main().catch((err) => {
  console.error(err);
});
