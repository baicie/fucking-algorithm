/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (root == nullptr)
            return 0;
        st.push(root);
        int result = 0;
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr)
            {
                result += node->left->val;
            }
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
            /* code */
        }
        return result;
    }
};
// @lc code=end
