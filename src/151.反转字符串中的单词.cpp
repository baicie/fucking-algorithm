/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        removeExtraSpaces(s);
        // 反转所有
        reverse(s, 0, s.size() - 1);

        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            /* code */
            // 反转最后一个字符串
            // 或者遇到了空格
            if (i == s.size() || s[i] == ' ')
            {
                // 开始 到结束i会多走一步
                reverse(s, start, i - 1);
                // 越过空格
                start = i + 1;
            }
        }
        return s;
    }

    void removeExtraSpaces(string &s)
    {
        // 移除多余的空格
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            if (s[fast] != ' ')
            {
                // slow从0开始有值 因为下面的while会走到 fast匹配到空格
                // slow此时赋值空格++
                // fast已经挪到了空格的下一个不为空格的字符
                if (slow != 0)
                    s[slow++] = ' ';
                // 当fast指针不为空格时
                // 值转移给slow 都右移
                while (fast < s.size() && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                    /* code */
                }
            }
        }
        s.resize(slow);
    }

    void reverse(string &s, int start, int end)
    {
        // 头尾指针
        for (int i = start, j = end; i < j; i++, j--)
        {
            /* code */
            swap(s[i], s[j]);
        }
    }
};
// @lc code=end
