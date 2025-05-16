/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *cur = root;
        TreeNode *parent = nullptr;

        while (cur && cur->val != key)
        {
            parent = cur;
            if (key < cur->val)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
            /* code */
        }
        if (!cur)
            return root;

        // 包含两个字节点
        if (cur->left && cur->right)
        {
            // 找右子树最小节点替代当前节点
            TreeNode *minNode = cur->right;
            TreeNode *minParent = cur;

            // 找到最小值
            while (minNode->left)
            {
                minParent = minNode;
                minNode = minNode->left;
                /* code */
            }

            // 替换值 值被借用了 现在问题换成了删除改minNode
            cur->val = minNode->val;
            cur = minNode;
            parent = minParent;
        }
        // 只有一个字节点/无字节点的情况
        TreeNode *child = cur->left ? cur->left : cur->right;
        // 没有父节点 基于上述条件 返回child
        if (!parent)
        {
            return child;
        }

        // 说明要删除的节点在左侧
        // 有父节点 字节点有0个或者一个 直接将child（null/childnode）赋值给父节点
        if (parent->left == cur)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }

        return root;
    }
};
// @lc code=end
