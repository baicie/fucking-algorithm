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
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *temp = cur->next->next->next;
            ListNode *temp1 = cur->next;
            ListNode *temp2 = temp1->next;

            cur->next = temp2;
            temp2->next = temp1;
            temp1->next = temp;

            cur = cur->next->next;
        }
        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
// @lc code=end
