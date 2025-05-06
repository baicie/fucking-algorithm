/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        vector<int> next(n, 0);
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
                /* code */
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
        int len = next[n - 1];
        return len > 0 && n % (n - len) == 0;
    }
};
// @lc code=end
