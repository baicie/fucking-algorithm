/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> p_que;
        queue<TreeNode *> q_que;
        p_que.push(p);
        q_que.push(q);
        while (!p_que.empty() && !q_que.empty())
        {
            TreeNode *p_node = p_que.front();
            p_que.pop();
            TreeNode *q_node = q_que.front();
            q_que.pop();
            if (p_node == nullptr && q_node == nullptr)
                continue;
            if (p_node == nullptr || q_node == nullptr)
                return false;
            if (p_node->val != q_node->val)
                return false;

            p_que.push(p_node->left);
            p_que.push(p_node->right);
            q_que.push(q_node->left);
            q_que.push(q_node->right);
        }
        return true;
    }
};
// @lc code=end
