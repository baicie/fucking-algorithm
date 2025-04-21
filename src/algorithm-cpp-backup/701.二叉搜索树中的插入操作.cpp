/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        TreeNode *cur = root;
        TreeNode *parent = root;
        while (cur != nullptr)
        {
            parent = cur;
            if (cur->val > val)
                cur = cur->left;
            else
                cur = cur->right;
            /* code */
        }
        TreeNode *node = new TreeNode(val);
        if (val < parent->val)
            parent->left = node;
        else
            parent->right = node;
        return root;
    }
};
// @lc code=end
