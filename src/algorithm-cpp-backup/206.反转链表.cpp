/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
#include <cstddef>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // 前一个结点 与 当前节点
        ListNode *pre = NULL;
        ListNode *cur = head;

        while (cur)
        {
            // 保存next节点
            ListNode *temp = cur->next;
            // 当前指向上一个
            cur->next = pre;
            // 右移
            pre = cur;
            // 右移
            cur = temp;
        }
        return pre;
    }
};
// @lc code=end
