/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        while (root && (root->val < low || root->val > high))
        {
            if (root->val < low)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
            /* code */
        }

        TreeNode *cur = root;
        while (cur)
        {
            while (cur->left && cur->left->val < low)
            {
                cur->left = cur->left->right;
                /* code */
            }
            cur = cur->left;
            /* code */
        }

        cur = root;
        while (cur)
        {
            while (cur->right && cur->right->val > high)
            {
                cur->right = cur->right->left;
                /* code */
            }
            cur = cur->right;

            /* code */
        }
        return root;
    }
};
// @lc code=end
