/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> stk;

        for (char c : s)
        {
            if (!stk.empty() && stk.top() == c)
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
            /* code */
        }
        string result;
        while (!stk.empty())
        {
            result += stk.top();
            stk.pop();
            /* code */
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
