/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dymmyHead = new ListNode(0);
        dymmyHead->next = head;
        ListNode *cur = dymmyHead;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *first = cur->next;
            ListNode *second = cur->next->next;

            // 1-> 3
            first->next = second->next;
            // 2-> 1
            second->next = first;
            // head -> 2
            cur->next = second;
            /* code */
            // next step
            cur = first;
        }
        return dymmyHead->next;
    }
};
// @lc code=end
