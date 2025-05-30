/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (char ch : s)
        {
            if (st.empty() || ch != st.top())
            {
                st.push(ch);
            }
            else
            {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
            /* code */
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
