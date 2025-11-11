const codes = [
  "8a2bc043-d3d5-41ea-8113-1e7f966e81bd",
  "bdfe2f5a-face-454a-b893-5a272b0c24be",
];

const tree = [
  {
    id: "81b35029-cb61-11ea-835c-0026b94b8d9a",
    label: "嘉荣集团",
    children: [
      {
        id: "4d2178e7-cc5e-4352-8914-dac3d98c6053",
        label: "总裁办",
        children: [
          {
            id: "d4f4f07a-1e1e-4e24-8bfc-605c127e5ccb",
            label: "外事组",
          },
        ],
      },
      {
        id: "6beb7231-3dad-49f4-8669-6945b85135a9",
        label: "品牌与商务中心",
        children: [
          {
            id: "bdfe2f5a-face-454a-b893-5a272b0c24be",
            label: "品牌文化与设计",
          },
          {
            id: "8a2bc043-d3d5-41ea-8113-1e7f966e81bd",
            label: "品牌公关与新媒体",
          },
          {
            id: "0554ee10-78e9-4ce1-acc3-7745a2b5d939",
            label: "商务行政组",
          },
        ],
      },
      {
        id: "b848eeba-3dc7-4bd3-8850-e6c844444931",
        label: "人力共享中心",
        children: [
          {
            id: "af9acdbd-854a-4c1f-8bf5-dc3799b22354",
            label: "组织发展组",
          },
          {
            id: "73bca37d-3af0-497c-85ad-5afe5ba18c74",
            label: "服务共享组",
          },
          {
            id: "622eeed9-c1cf-44e0-bd97-3dea06f42ead",
            label: "招聘共享组",
          },
          {
            id: "11b4ff28-21b1-11ec-92db-3448edf5b554",
            label: "人才发展组",
          },
          {
            id: "3a5ae410-21b1-11ec-92db-3448edf5b554",
            label: "人力资源信息化建设组",
          },
        ],
      },
    ],
  },
];

interface TreeNode {
  id: string;
  label: string;
  children?: TreeNode[];
}

function findCellFromTree(tree: TreeNode[], ids: string[]): TreeNode[] {
  const res: TreeNode[] = [];

  tree.forEach((node) => {
    if (ids.includes(node.id)) {
      res.push(node);
    }

    if (node.children) {
      res.push(...findCellFromTree(node.children, ids));
    }
  });

  return res;
}

const res = findCellFromTree(tree, codes);

console.log("res", res);
