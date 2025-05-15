/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
#include <stack>
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;

        stack<TreeNode *> stk;
        stk.push(root);
        int sum = 0;

        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();

            if (node->left && !node->left->left && !node->left->right)
            {
                sum += node->left->val;
            }

            if (node->left)
                stk.push(node->left);
            if (node->right)
                stk.push(node->right);
            /* code */
        }
        return sum;
    }
};
// @lc code=end
