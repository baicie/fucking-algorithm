/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
#include <stack>
#include <climits>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        stack<TreeNode *> stack;
        TreeNode *current = root;
        int minDiff = INT_MAX;
        int prev = -1;
        while (!stack.empty() || current != nullptr)
        {
            /* code */
            while (current != nullptr)
            {
                /* code */
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            stack.pop();
            if (prev != -1)
            {
                minDiff = min(minDiff, current->val - prev);
            }
            prev = current->val;
            current = current->left;
        }
        return minDiff;
    }
};
// @lc code=end
