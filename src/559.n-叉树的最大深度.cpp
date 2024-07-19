/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    int maxDepth(Node *root)
    {
        int depth = 0;
        queue<Node *> que;
        if (root == nullptr)
            return depth;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            depth += 1;
            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                for (int i = 0; i < node->children.size(); i++)
                {
                    if (node->children[i])
                        que.push(node->children[i]);
                }
            }
        }

        return depth;
    }
};
// @lc code=end
