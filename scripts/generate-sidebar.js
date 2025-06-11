import { readdirSync, statSync, writeFileSync } from 'fs';
import { join, relative, basename } from 'path';

// 配置项
const CONFIG = {
  docsDir: 'docs',
  ignoreDirs: ['.vitepress', 'public', 'assets'],
  ignoreFiles: ['.DS_Store', 'index.md'],
  groupSize: 100, // 每组显示的文件数量
};

// 编码文件路径，保持中文可读性
function encodeFilePath(path) {
  return path
    .split('/')
    .map(segment => 
      // 如果是中文或包含特殊字符，则进行编码
      /[\u4e00-\u9fa5\s\(\)\[\]\{\}\+\*\?\^\$\|]/.test(segment) 
        ? encodeURIComponent(segment)
        : segment
    )
    .join('/');
}

// 获取指定目录下的所有 markdown 文件
function getMarkdownFiles(dir) {
  const files = readdirSync(dir);
  const markdownFiles = [];

  for (const file of files) {
    const fullPath = join(dir, file);
    const stat = statSync(fullPath);

    if (stat.isDirectory() && !CONFIG.ignoreDirs.includes(file)) {
      markdownFiles.push(...getMarkdownFiles(fullPath));
    } else if (
      stat.isFile() &&
      file.endsWith('.md') &&
      !CONFIG.ignoreFiles.includes(file)
    ) {
      markdownFiles.push(fullPath);
    }
  }

  return markdownFiles;
}

// 生成分组
function generateGroups(files, basePath) {
  const groups = new Map();
  
  files.forEach(file => {
    const relativePath = relative(basePath, file);
    const fileNumber = parseInt(basename(file).split('.')[0]);
    
    if (isNaN(fileNumber)) return;
    
    const groupIndex = Math.floor(fileNumber / CONFIG.groupSize);
    const groupStart = groupIndex * CONFIG.groupSize;
    const groupEnd = (groupIndex + 1) * CONFIG.groupSize;
    const groupName = `Group ${groupStart}-${groupEnd}`;
    
    if (!groups.has(groupName)) {
      groups.set(groupName, []);
    }
    
    groups.get(groupName).push({
      text: basename(file, '.md'),
      link: '/' + encodeFilePath(relativePath.replace(/\.md$/, '')),
    });
  });
  
  return Array.from(groups.entries()).map(([text, items]) => ({
    text,
    collapsed: true,
    items: items.sort((a, b) => {
      const numA = parseInt(a.text.split('.')[0]);
      const numB = parseInt(b.text.split('.')[0]);
      return numA - numB;
    }),
  }));
}

// 生成侧边栏配置
function generateSidebar() {
  const docsPath = join(process.cwd(), CONFIG.docsDir);
  const algorithmPath = join(docsPath, 'algorithm');
  const babelPath = join(docsPath, 'babel');
  
  // 生成算法笔记的侧边栏
  const algorithmFiles = getMarkdownFiles(algorithmPath);
  const algorithmSidebar = generateGroups(algorithmFiles, docsPath);
  
  // 生成 Babel 笔记的侧边栏
  const babelFiles = getMarkdownFiles(babelPath);
  const babelItems = babelFiles
    .map(file => {
      const relativePath = relative(babelPath, file);
      return {
        text: basename(file, '.md')
          .replace(/^\d+\s+/, '') // 移除数字前缀
          .replace(/\s+/g, ' '), // 规范化空格
        link: encodeFilePath(relativePath.replace(/\.md$/, '')),
      };
    })
    .sort((a, b) => {
      const numA = parseInt(a.link.match(/\d+/)?.[0] || 0);
      const numB = parseInt(b.link.match(/\d+/)?.[0] || 0);
      return numA - numB;
    });

  // 生成最终的配置
  const sidebarConfig = {
    '/algorithm/': {
      base: '/algorithm/',
      items: [
        {
          text: '简介',
          link: 'algorithm',
        },
        ...algorithmSidebar,
      ],
    },
    '/babel/': {
      base: '/babel/',
      items: [
        {
          text: 'Babel笔记',
          items: babelItems,
        },
      ],
    },
  };

  // 将配置写入文件
  const configContent = `export default ${JSON.stringify(sidebarConfig, null, 2)}`;
  writeFileSync(
    join(process.cwd(), 'docs/.vitepress/config/sidebar.ts'),
    configContent
  );
}

generateSidebar(); 