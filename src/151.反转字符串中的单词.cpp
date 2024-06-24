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
        reverse(s, 0, s.size() - 1);

        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            /* code */
            if (i == s.size() || s[i] == ' ')
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }

    void removeExtraSpaces(string &s)
    {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            if (s[fast] != ' ')
            {
                if (slow != 0)
                    s[slow++] = ' ';
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
        for (int i = start, j = end; i < j; i++, j--)
        {
            /* code */
            swap(s[i], s[j]);
        }
    }
};
// @lc code=end
