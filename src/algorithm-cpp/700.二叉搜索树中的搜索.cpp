/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root)
        {
            if (root->val == val)
                return root;
            else if (root->val > val)
                root = root->left;
            else
                root = root->right;
            /* code */
        }
        return nullptr;
    }
};
// @lc code=end
