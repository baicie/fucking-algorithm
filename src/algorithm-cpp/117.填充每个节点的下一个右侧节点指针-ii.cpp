/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
#include <cstddef>
#include <queue>
using namespace std;
// class Node
// {
// public:
//     int val;
//     Node *left;
//     Node *right;
//     Node *next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node *_left, Node *_right, Node *_next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            Node *prev = nullptr;

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (prev)
                {
                    prev->next = node;
                }
                prev = node;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                /* code */
            }

            /* code */
        }
        return root;
    }
};
// @lc code=end
