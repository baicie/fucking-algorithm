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
        TreeNode *current = root;
        while (current != nullptr)
        {
            if (current->val == val)
            {
                return current;
            }
            else if (current->val > val)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return nullptr;
    }
};
// @lc code=end
