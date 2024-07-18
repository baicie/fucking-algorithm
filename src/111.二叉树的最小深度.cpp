/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
#include <queue>
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
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> que;
        int minDepth = 0;
        if (root != nullptr)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            minDepth += 1;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (!node->left && !node->right)
                {
                    return minDepth;
                }
            }

            /* code */
        }

        return minDepth;
    }
};
// @lc code=end
