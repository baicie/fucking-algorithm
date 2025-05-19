/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    struct NodeInfo
    {
        TreeNode *node;
        int left;
        int right;
    };
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        int left = 0, right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        queue<NodeInfo> q;
        q.push({root, left, right});

        while (!q.empty())
        {
            NodeInfo current = q.front();
            q.pop();

            TreeNode *node = current.node;
            int l = current.left;
            int r = current.right;
            int m = l + (r - l) / 2;

            if (l < m)
            {
                int lm = l + (m - 1 - l) / 2;
                TreeNode *leftNode = new TreeNode(nums[lm]);
                node->left = leftNode;
                q.push({leftNode, l, m - 1});
            }

            if (m < r)
            {
                int rm = m + 1 + (r - (m + 1)) / 2;
                TreeNode *rightNode = new TreeNode(nums[rm]);
                node->right = rightNode;
                q.push({rightNode, m + 1, r});
            }
        }
        return root;
    }
};
// @lc code=end
