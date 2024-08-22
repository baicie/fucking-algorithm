/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        int result = __INT_MAX__;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                if (pre != nullptr)
                {
                    result = min(result, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;
            }
            /* code */
        }
        return result;
    }
};
// @lc code=end
