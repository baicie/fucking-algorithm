/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
#include <vector>
#include <stack>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty() || postorder.empty())
            return nullptr;
        TreeNode *root = new TreeNode(postorder.back());
        postorder.pop_back();

        stack<TreeNode *> stk;
        stk.push(root);

        int inorderIndex = inorder.size() - 1;

        for (int i = postorder.size() - 1; i >= 0; --i)
        {
            TreeNode *node = stk.top();
            if (node->val != inorder[inorderIndex])
            {
                node->right = new TreeNode(postorder[i]);
                stk.push(node->right);
            }
            else
            {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop();
                    --inorderIndex;
                    /* code */
                }
                node->left = new TreeNode(postorder[i]);
                stk.push(node->left);
            }
            /* code */
        }
        return root;
    }
};

// 	1.	循环初始化:
// 	•	i初始化为postorder.size() - 1，即后序遍历的最后一个元素索引。
// 	•	每次循环，i递减，表示我们在后序遍历中从后向前处理节点。
// 	2.	获取栈顶节点:
// 	•	TreeNode* node = stk.top(); 获取栈顶节点。这是当前处理的节点，也是当前子树的根节点。
// 	3.	判断当前节点是否是右子节点:
// 	•	if (node->val != inorder[inorderIndex]) 检查栈顶节点的值是否等于当前中序遍历的值。如果不等，说明当前后序遍历的节点是右子节点。
// 	•	node->right = new TreeNode(postorder[i]); 创建新的右子节点，并将其赋值给当前节点的右子树。
// 	•	stk.push(node->right); 将新的右子节点推入栈中。
// 	4.	处理左子节点:
// 	•	如果当前节点的值等于中序遍历的值，说明我们需要处理左子节点。
// 	•	while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) 循环检查栈顶节点的值是否等于当前中序遍历的值。如果相等，说明当前节点及其所有右子节点都已经处理完毕。
// 	•	node = stk.top(); 更新当前节点为栈顶节点。
// 	•	stk.pop(); 弹出栈顶节点，表示我们已经处理完该节点。
// 	•	--inorderIndex; 中序遍历索引左移，准备处理下一个节点。
// 	•	node->left = new TreeNode(postorder[i]); 创建新的左子节点，并将其赋值给当前节点的左子树。
// 	•	stk.push(node->left); 将新的左子节点推入栈中。

// 示例解释：

// 假设我们有以下中序遍历和后序遍历：

// 	•	中序遍历：[9, 3, 15, 20, 7]
// 	•	后序遍历：[9, 15, 7, 20, 3]

// 构建过程如下：

// 	1.	初始化根节点为3，并将其推入栈中。
// 	2.	处理20：因为3 != 7（当前中序遍历的末尾值），所以20是3的右子节点。
// 	3.	处理7：因为20 != 7，所以7是20的右子节点。
// 	4.	处理15：因为7 == 7，所以开始处理左子节点。弹出7和20，再创建15为20的左子节点。
// 	5.	处理9：因为15 == 15，继续处理左子节点。弹出15和3，再创建9为3的左子节点。

// 通过上述步骤，完成了二叉树的构建。
// @lc code=end
