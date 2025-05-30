/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <vector>
#include <string>
#include <array>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int sLen = s.length(), pLen = p.length();
        vector<int> ans{};
        if (pLen > sLen)
            return ans;

        array<int, 26> smp{0};
        array<int, 26> pmp{0};
        for (int i = 0; i < pLen; i++)
        {
            smp[s[i] - 'a']++;
            pmp[p[i] - 'a']++;
        }

        if (smp == pmp)
        {
            ans.emplace_back(0);
        }

        for (int i = pLen; i < sLen; i++)
        {
            // 除去前面的
            smp[s[i - pLen] - 'a']--;
            smp[s[i] - 'a']++;
            if (smp == pmp)
            {
                ans.emplace_back(i - pLen + 1);
            }
        }
        return ans;
    }
};
// @lc code=end
