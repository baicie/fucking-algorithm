/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool isSametree(TreeNode *a, TreeNode *b)
    {
        stack<TreeNode *> a_st, b_st;
        a_st.push(a), b_st.push(b);
        while (!a_st.empty() && !b_st.empty())
        {
            TreeNode *a_node = a_st.top();
            TreeNode *b_node = b_st.top();
            a_st.pop(), b_st.pop();
            if (a_node == nullptr && b_node == nullptr)
            {
                continue;
            }
            if (a_node == nullptr || b_node == nullptr)
            {
                return false;
            }
            if (a_node->val != b_node->val)
            {
                return false;
            }
            a_st.push(a_node->right);
            a_st.push(a_node->left);

            b_st.push(b_node->right);
            b_st.push(b_node->left);
        }
        return a_st.empty() && b_st.empty();
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (subRoot == nullptr)
            return true;
        if (root == nullptr)
            return false;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            if (node->val == subRoot->val && isSametree(node, subRoot))
            {
                return true;
            }
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return false;
    }
};
// @lc code=end
