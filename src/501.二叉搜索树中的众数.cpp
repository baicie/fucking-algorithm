/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
#include <vector>
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
    vector<int> findMode(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        int maxCount = 0;
        int count = 0;
        vector<int> result;
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

                if (pre == nullptr)
                {
                    count = 1;
                }
                else if (pre->val == cur->val)
                {
                    count++;
                }
                else
                {
                    count + 1;
                }
                if (count == maxCount)
                {
                    result.push_back(cur->val);
                }

                if (count > maxCount)
                {
                    maxCount = count;
                    result.clear();
                    result.push_back(cur->val);
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
