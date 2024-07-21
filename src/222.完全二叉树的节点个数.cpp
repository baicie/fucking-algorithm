/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (root != nullptr)
            st.push(root);
        int count = 0;
        while (!st.empty())
        {
            int size = st.size();
            for (int i = 0; i < size; i++)
            {
                /* code */
                TreeNode *node = st.top();
                st.pop();
                count++;
                if (node->right)
                    st.push(node->right);
                if (node->left)
                    st.push(node->left);
            }
        }
        return count;
    }
};
// @lc code=end
