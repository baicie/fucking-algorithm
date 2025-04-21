/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <queue>
#include <climits>
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
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);
        vector<int> result;
        while (!que.empty())
        {
            int size = que.size();
            int row_min = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                row_min = node->val > row_min ? node->val : row_min;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(row_min);
            row_min = INT_MIN;
        }

        return result;
    }
};
// @lc code=end
