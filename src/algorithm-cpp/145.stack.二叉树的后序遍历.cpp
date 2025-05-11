/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left)
            {
                st.push(node->left);
            }
            if (node->right)
            {
                st.push(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
