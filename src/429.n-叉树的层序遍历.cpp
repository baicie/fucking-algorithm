/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
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
        queue<Node *> que;
        if (root != nullptr)
            que.push(root);
        vector<vector<int>> res;
        while (!que.empty())
        {
            vector<int> row;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                row.push_back(node->val);
                for (int j = 0; j < node->children.size(); j++)
                {
                    if (node->children[j])
                        que.push(node->children[j]);
                }
            }
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end
