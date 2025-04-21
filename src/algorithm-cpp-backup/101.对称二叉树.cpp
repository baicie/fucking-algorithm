
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <queue>
using namespace std;
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty())
        {
            TreeNode *left = que.front();
            que.pop();
            TreeNode *right = que.front();
            que.pop();
            if (left == nullptr && right == nullptr)
            {
                continue;
            }
            if (left == nullptr || right == nullptr)
            {
                return false;
            }
            if (left->val != right->val)
            {
                return false;
            }
            else
            {
                que.push(left->left);
                que.push(right->right);
                que.push(left->right);
                que.push(right->left);
            }
        }
        return true;
    }
};
// @lc code=end
