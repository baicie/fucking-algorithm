/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */

// @lc code=start
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1)
            return root2;

        stack<pair<TreeNode *, TreeNode *>> st;
        st.push({root1, root2});

        while (!st.empty())
        {
            auto [node1, node2] = st.top();
            st.pop();

            if (!node1 || !node2)
                continue;

            node1->val += node2->val;

            if (!node1->left)
            {
                node1->left = node2->left;
            }
            else
            {
                st.push({node1->left, node2->left});
            }

            if (!node1->right)
            {
                node1->right = node2->right;
            }
            else
            {
                st.push({node1->right, node2->right});
            }
        }
        return root1;
    }
};
// @lc code=end
