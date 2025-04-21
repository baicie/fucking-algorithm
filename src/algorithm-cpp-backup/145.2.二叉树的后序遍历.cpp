/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        if (root == nullptr)
            return res;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            res.push_back(cur->val);
            if (cur->left)
                st.push(cur->left);
            if (cur->right)
                st.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
