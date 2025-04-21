/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0); // 创建虚拟头节点
        dummyHead->next = head;
        ListNode *cur = dummyHead; // 先行指针
        ListNode *pre = dummyHead; // 跟随指针

        // 让cur先走n步
        for (int i = 0; i < n; i++)
        {
            cur = cur->next;
        }

        // 让cur和pre一起走，直到cur走到链表末尾
        while (cur->next != nullptr)
        {
            cur = cur->next;
            pre = pre->next;
        }

        // 此时pre指向待删除节点的前一个节点
        pre->next = pre->next->next;

        // 返回新的头节点
        return dummyHead->next;
    }
};

// @lc code=end
