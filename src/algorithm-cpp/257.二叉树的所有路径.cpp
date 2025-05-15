/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        if (!root)
            return result;

        stack<pair<TreeNode *, string>> stk;
        stk.push({root, to_string(root->val)});

        while (!stk.empty())
        {
            auto [node, path] = stk.top();
            stk.pop();

            if (!node->left && !node->right)
            {
                result.push_back(path);
            }

            if (node->right)
            {
                stk.push({node->right, path + "->" + to_string(node->right->val)});
            }

            if (node->left)
            {
                stk.push({node->left, path + "->" + to_string(node->left->val)});
            }
            /* code */
        }
        return result;
    }
};
// @lc code=end
