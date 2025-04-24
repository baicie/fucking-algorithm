/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = nullptr;
        ListNode *fast = head;
        ListNode *slow = nullptr;

        while (fast)
        {
            temp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = temp;
            /* code */
        }
        return slow;
    }
};
// @lc code=end
