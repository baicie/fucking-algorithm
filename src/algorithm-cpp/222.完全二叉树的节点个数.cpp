/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int getHeight(TreeNode *node)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = node->left;
            /* code */
        }
        return height;
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == rightHeight)
        {
            return (1 << leftHeight) + countNodes(root->right);
        }
        else
        {
            // 高度不相等 右子树是满的求左侧
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
};
// @lc code=end
