/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include <stack>
using namespace std;
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return checkheight(root) != -1;
    }
    int checkheight(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int leftHeight = checkheight(node->left);
        if (leftHeight == -1)
            return -1;
        int rightHright = checkheight(node->right);
        if (rightHright == -1)
            return -1;

        if (abs(leftHeight - rightHright) > 1)
        {
            return -1;
        }
        return max(leftHeight, rightHright) + 1;
    }
};
// @lc code=end
