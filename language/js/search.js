// 示例树形数据
const treeData = [
  {
    id: 1,
    name: "Node 1",
    children: [
      {
        id: 2,
        name: "Node 1.1",
        children: [
          {
            id: 3,
            name: "Node 1.1.1",
          },
        ],
      },
    ],
  },
  {
    id: 4,
    name: "Node 2",
  },
];

// 模糊匹配函数
function fuzzySearchTree(data, searchString) {
  const results = [];

  function search(node, query) {
    if (node.name.includes(query)) {
      results.push(node);
    }
    if (node.children) {
      for (const child of node.children) {
        search(child, query);
      }
    }
  }

  for (const item of data) {
    search(item, searchString);
  }

  return results;
}

const searchString = "Node 1.1";
const matchingNodes = fuzzySearchTree(treeData, searchString);
console.log("匹配的节点：", matchingNodes);
