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
        if (!root)
            return new TreeNode(val);

        TreeNode *cur = root;
        while (true)
        {
            if (val < cur->val)
            {
                if (cur->left)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (cur->right)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            /* code */
        }
        return root;
    }
};
// @lc code=end
