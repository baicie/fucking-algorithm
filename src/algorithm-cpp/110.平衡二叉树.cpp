/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
#include <algorithm>
using namespace std;
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
        if (!node)
            return 0;

        int left = getHeight(node->left);
        if (left == -1)
            return -1;

        int right = getHeight(node->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) != -1;
    }
};
// @lc code=end
