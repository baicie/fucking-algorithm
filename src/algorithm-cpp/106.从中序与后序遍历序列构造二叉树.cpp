/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.empty())
            return nullptr;

        int inIndex = inorder.size() - 1;
        int postIndex = postorder.size() - 1;

        TreeNode *root = new TreeNode(postorder[postIndex--]);
        stack<TreeNode *> st;
        st.push(root);

        while (postIndex >= 0)
        {
            TreeNode *node = st.top();
            // inorder 对不上为右子树
            if (node->val != inorder[inIndex])
            {
                node->right = new TreeNode(postorder[postIndex--]);
                st.push(node->right);
            }
            else
            {
                while (!st.empty() && st.top()->val == inorder[inIndex])
                {
                    // 栈底是跟节点
                    node = st.top();
                    st.pop();
                    inIndex--;
                    /* code */
                }
                node->left = new TreeNode(postorder[postIndex--]);
                st.push(node->left);
            }
            /* code */
        }
        return root;
    }
};
// @lc code=end
