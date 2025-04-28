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
    void removeExtraSpaces(string &s)
    {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            // 相当于fast指针跳过空格
            if (s[fast] != ' ')
            {
                // 相当于开始新一个单词处理 并不包含开头的单词
                if (slow != 0)
                {
                    s[slow++] = ' ';
                }
                while (fast < s.size() && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                    /* code */
                }
            }
            /* code */
        }
        // 改变原长度
        s.resize(slow);
    }
    string reverseWords(string s)
    {
        removeExtraSpaces(s);
        reverse(s.begin(), s.end());

        int start = 0;
        // 需要判断最后一个单词 因为没有空格只能用size
        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size() || s[i] == ' ')
            {
                // 最后一个单词不会越界 相当于size+1
                // reverse是左闭右开区间
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
// @lc code=end
