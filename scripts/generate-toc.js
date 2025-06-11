const fs = require('fs');
const path = require('path');

// 忽略的目录
const IGNORE_DIRS = ['.vitepress', 'public', 'node_modules'];
// 支持的文件类型
const SUPPORTED_EXTENSIONS = ['.md'];

function generateSidebarConfig(dirPath, relativePath = '') {
  const items = [];
  const files = fs.readdirSync(dirPath);

  // 过滤并排序文件
  const sortedFiles = files
    .filter(file => {
      const fullPath = path.join(dirPath, file);
      const stat = fs.statSync(fullPath);
      const ext = path.extname(file);
      
      // 忽略特定目录和非支持的文件类型
      if (stat.isDirectory() && IGNORE_DIRS.includes(file)) return false;
      if (stat.isFile() && !SUPPORTED_EXTENSIONS.includes(ext)) return false;
      
      return true;
    })
    .sort((a, b) => {
      // 数字开头的文件按数字排序
      const numA = parseInt(a);
      const numB = parseInt(b);
      if (!isNaN(numA) && !isNaN(numB)) return numA - numB;
      return a.localeCompare(b);
    });

  for (const file of sortedFiles) {
    const fullPath = path.join(dirPath, file);
    const stat = fs.statSync(fullPath);
    const relativeName = path.join(relativePath, file);

    if (stat.isDirectory()) {
      const dirItems = generateSidebarConfig(fullPath, relativeName);
      if (dirItems.length > 0) {
        items.push({
          text: file,
          collapsed: false,
          items: dirItems
        });
      }
    } else if (path.extname(file) === '.md' && file !== 'index.md') {
      // 读取文件内容获取标题
      const content = fs.readFileSync(fullPath, 'utf-8');
      const titleMatch = content.match(/^#\s+(.+)$/m);
      const title = titleMatch ? titleMatch[1] : file.replace('.md', '');
      
      // 生成 VitePress 侧边栏项
      items.push({
        text: title,
        link: '/' + relativeName.replace(/\\/g, '/').replace('.md', '') // 确保使用正斜杠并移除 .md 扩展名
      });
    }
  }

  return items;
}

function updateVitePressConfig() {
  const docsPath = path.join(process.cwd(), 'docs');
  const configPath = path.join(docsPath, '.vitepress/config.js');
  
  // 读取现有配置文件
  let configContent = fs.readFileSync(configPath, 'utf-8');
  
  // 获取所有文档目录
  const dirs = fs.readdirSync(docsPath)
    .filter(dir => {
      const fullPath = path.join(docsPath, dir);
      return fs.statSync(fullPath).isDirectory() && !IGNORE_DIRS.includes(dir);
    });

  // 为每个目录生成侧边栏配置
  const sidebar = {};
  for (const dir of dirs) {
    const fullPath = path.join(docsPath, dir);
    const sidebarItems = generateSidebarConfig(fullPath, dir);
    if (sidebarItems.length > 0) {
      sidebar['/' + dir + '/'] = sidebarItems;
    }
  }

  // 更新配置文件中的 sidebar 部分
  const sidebarStr = JSON.stringify(sidebar, null, 2)
    .replace(/"([^"]+)":/g, '$1:') // 移除对象键的引号
    .replace(/"link":/g, 'link:')
    .replace(/"text":/g, 'text:')
    .replace(/"collapsed":/g, 'collapsed:')
    .replace(/"items":/g, 'items:');

  // 使用正则表达式替换 sidebar 配置
  const newConfigContent = configContent.replace(
    /sidebar:\s*{[^}]*}/s,
    `sidebar: ${sidebarStr}`
  );

  // 写入更新后的配置
  fs.writeFileSync(configPath, newConfigContent);
  console.log('Updated VitePress sidebar config at:', configPath);
}

// 执行配置更新
updateVitePressConfig(); 