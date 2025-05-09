/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
#include <stack>
#include <unordered_map>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        stack<TreeNode *> st;
        unordered_map<TreeNode *, TreeNode *> parent;
        parent[root] = nullptr;
        st.push(root);

        while (parent.find(p) == parent.end() || parent.find(q) == parent.end())
        {
            TreeNode *node = st.top();
            st.pop();
            if (node->left)
            {
                parent[node->left] = node;
                st.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                st.push(node->right);
            }
            /* code */
        }

        unordered_map<TreeNode *, bool> ancestors;
        while (p != nullptr)
        {
            ancestors[p] = true;
            p = parent[p];
        }

        while (ancestors.find(q) == ancestors.end())
        {
            q = parent[q];
        }

        return q;
    }
};
// @lc code=end
