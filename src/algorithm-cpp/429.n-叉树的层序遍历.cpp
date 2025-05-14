/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
// class Node
// {
// public:
//     int val;
//     vector<Node *> children;

//     Node() {}

//     Node(int _val)
//     {
//         val = _val;
//     }

//     Node(int _val, vector<Node *> _children)
//     {
//         val = _val;
//         children = _children;
//     }
// };

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> levelResult;

            for (int i = 0; i < levelSize; i++)
            {
                Node *node = q.front();
                q.pop();
                levelResult.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++)
                {
                    q.push(node->children[i]);
                }
            }
            result.push_back(levelResult);
        }

        return result;
    }
};
// @lc code=end
