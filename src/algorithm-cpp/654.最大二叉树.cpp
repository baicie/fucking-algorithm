/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        stack<TreeNode *> st;

        for (int num : nums)
        {
            TreeNode *cur = new TreeNode(num);
            while (!st.empty() && st.top()->val < num)
            {
                cur->left = st.top();
                st.pop();
                /* code */
            }
            if (!st.empty())
            {
                st.top()->right = cur;
            }
            st.push(cur);
            /* code */
        }

        while (st.size() > 1)
        {
            st.pop();
            /* code */
        }
        return st.top();
    }
};
// @lc code=end
