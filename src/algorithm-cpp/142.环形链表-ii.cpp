/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                ListNode *cur = head;
                while (cur != slow)
                {
                    cur = cur->next;
                    slow = slow->next;
                    /* code */
                }
                return cur;
            }
            /* code */
        }

        return nullptr;
    }
};
// @lc code=end
