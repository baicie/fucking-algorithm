/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start

//  Definition for a binary tree node.
#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == nullptr)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);
        }
        return result;
    }
};
// @lc code=end
