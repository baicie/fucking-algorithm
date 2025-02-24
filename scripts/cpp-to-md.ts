import { globSync } from "fast-glob";
import fs from "node:fs";
import path from "node:path";
import fse from "fs-extra";

interface SliderItem {
  text: string;
  link?: string;
  index: number;
  collapsed?: boolean;
  items?: Partial<SliderItem>[];
}

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

let sidebar = `
export default 
`;
const sidebars: SliderItem[] = [];

const files = globSync("../src/algorithm-cpp/*.cpp", {
  cwd: __dirname,
  onlyFiles: true,
  absolute: true,
});

function sortSlider() {
  const res = sidebars.sort((a, b) => a.index - b.index);
  const maxGroup = Math.ceil(res[res.length - 1].index / 100);
  const tree = Array(maxGroup)
    .fill(null)
    .map((_, index) => {
      const min = index * 100 - 1;
      const max = (index + 1) * 100;
      const treeItem: Partial<SliderItem> = {
        text: `Group ${min}-${max}`,
        collapsed: true,
        items: res
          .filter((item) => item.index >= min && item.index <= max)
          .map((item) => ({
            text: item.text,
            link: item.link,
          })),
      };
      return treeItem;
    });
  sidebar += JSON.stringify(tree);
  fs.writeFileSync(sliderPath, sidebar, { encoding: "utf-8" });
}

async function main() {
  // empty
  fse.emptyDirSync(vitePressDocPath);
  //   cp indexmd
  fse.copyFileSync(
    algorithmMDPath,
    path.resolve(vitePressDocPath, "algorithm.md")
  );

  for (const file of files) {
    const fileName = path.basename(file, path.extname(file));
    const tagetPath = `${path.resolve(vitePressDocPath, fileName)}.md`;
    const content = fs.readFileSync(file, { encoding: "utf-8" });
    const newContent = `\`\`\` cpp
        ${content}
    \`\`\`
    `;
    fs.writeFileSync(tagetPath, newContent, { encoding: "utf-8" });
    sidebars.push({
      text: path.basename(fileName),
      link: `/${encodeURIComponent(fileName)}`,
      index: parseInt(fileName.split(".")[0]),
    });
  }
  sortSlider();
}

main().catch((err) => {
  console.error(err);
});
