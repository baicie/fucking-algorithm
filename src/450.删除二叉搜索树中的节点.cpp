/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *parent = nullptr;
        TreeNode *current = root;

        while (current && current->val != key)
        {
            parent = current;
            if (key < current->val)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
            /* code */
        }
        if (!current)
            return root;

        if (!current->left || !current->right)
        {
            TreeNode *newChild = current->left ? current->left : current->right;
            if (!parent)
            {
                return newChild;
            }
            if (parent->left == current)
            {
                parent->left = newChild;
            }
            else
            {
                parent->right = newChild;
            }
        }
        else
        {
            TreeNode *minNodeParent = current;
            TreeNode *minNode = current->right;

            while (minNode->left)
            {
                minNodeParent = minNode;
                minNode = minNode->left;
            }
            current->val = minNode->val;
            if (minNodeParent->left == minNode)
            {
                minNodeParent->left = minNode->right;
            }
            else
            {
                minNodeParent->right = minNode->right;
            }
            delete minNode;
        }
        return root;
    }
};
// @lc code=end
