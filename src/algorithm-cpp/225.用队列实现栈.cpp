/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>
using namespace std;
class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

    void transfer()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
    }

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        transfer();
        int topElement = q1.front();
        q1.pop();
        swap(q1, q2);
        return topElement;
    }

    int top()
    {
        transfer();
        int topElement = q1.front();
        q1.pop();
        q2.push(topElement);
        swap(q1, q2);
        return topElement;
    }

    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
