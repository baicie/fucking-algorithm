/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode *convertBST(TreeNode *root)
    {
        if (!root)
            return nullptr;
        stack<TreeNode *> st;
        int sum = 0;
        TreeNode *current = root;
        while (current != nullptr || !st.empty())
        {
            /* code */
            while (current != nullptr)
            {
                st.push(current);
                current = current->right;
                /* code */
            }
            current = st.top();
            st.pop();

            sum += current->val;
            current->val = sum;
            current = current->left;
        }
        return root;
    }
};
// @lc code=end
