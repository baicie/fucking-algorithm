/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
#include <vector>
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);
        vector<double> res;
        while (!que.empty())
        {
            /* code */
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                sum += node->val;
                if (i == size - 1)
                {
                    res.push_back(sum / size);
                }
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);

                /* code */
            }
        }

        return res;
    }
};
// @lc code=end
