/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        stack<pair<TreeNode *, int>> st;
        st.push({root, root->val});
        while (!st.empty())
        {
            auto [node, currentSum] = st.top();
            st.pop();

            if (!node->left && !node->right && currentSum == targetSum)
            {
                return true;
            }
            if (node->right)
            {
                st.push({node->right, currentSum + node->right->val});
            }
            if (node->left)
            {
                st.push({node->left, currentSum + node->left->val});
            }
            /* code */
        }
        return false;
    }
};
// @lc code=end
