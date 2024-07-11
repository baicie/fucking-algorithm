/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        traversal(root, res);
        return res;
    }
    void traversal(TreeNode *cur, vector<int> &res)
    {
        if (cur == nullptr)
            return;
        traversal(cur->left, res);
        traversal(cur->right, res);
        res.push_back(cur->val);
    }
};
// @lc code=end
