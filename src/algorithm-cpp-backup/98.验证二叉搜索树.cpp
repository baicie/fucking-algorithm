/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = pre = nullptr;

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
                if (pre != nullptr && cur->val <= pre->val)
                {
                    return false;
                }
                pre = cur;
                cur = cur->right;
            }
            /* code */
        }
        return true;
    }
};
// @lc code=end
