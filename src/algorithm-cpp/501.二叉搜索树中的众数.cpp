/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
#include <stack>
#include <vector>
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
        int count = 0;
        int maxCount = 0;
        stack<TreeNode *> st;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        vector<int> result;

        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();

            if (prev)
            {
                if (prev->val == cur->val)
                {
                    count++;
                }
                else
                {
                    count = 1;
                }
            }
            else
            {
                count = 1;
            }

            if (count == maxCount)
            {
                result.push_back(cur->val);
            }
            else if (count > maxCount)
            {
                maxCount = count;
                result = {cur->val};
            }

            prev = cur;
            cur = cur->right;
        }

        return result;
    }
};
// @lc code=end
