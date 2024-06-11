/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        ListNode *pre = dummyHead;
        for (int i = 0; i < n && cur->next != nullptr; i++)
        {
            cur = cur->next;
        }
        cur = cur->next;
        while (cur != nullptr)
        {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return dummyHead->next;
    }
};
// @lc code=end
