/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.length() - 1, j = t.length() - 1;
        int skipI = 0, skipJ = 0;
        while (i >= 0 || j >= 0)
        {
            // 反向遍历 直到第一个字符
            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    skipI++, i--;
                }
                else if (skipI > 0)
                {
                    skipI--, i--;
                }
                else
                {
                    break;
                }
            }

            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    skipJ++, j--;
                }
                else if (skipJ > 0)
                {
                    skipJ--, j--;
                }
                else
                {
                    break;
                }
            }

            // 判断结束条件
            // st 都有存量 判断当前指向是否相同
            if (i >= 0 && j >= 0)
            {
                if (s[i] != t[j])
                {
                    return false;
                }
                // 不同直接结束 相同继续循环
            }
            // 当出现一个走完了 另一个没走完长度不等 出现了-1？
            else
            {
                if (i >= 0 || j >= 0)
                {
                    return false;
                }
            }

            i--, j--;
        }
        return true;
    }
};
// @lc code=end
