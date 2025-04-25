/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> count;
        for (char c : s)
        {
            count[c]++;
        }
        for (char c : t)
        {
            count[c]--;
            /* code */
        }
        for (auto &[k, v] : count)
        {
            if (v != 0)
                return false;
            /* code */
        }
        return true;
    }
};
// @lc code=end
