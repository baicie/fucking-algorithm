/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 可以使用数组进行判断
        if (t.length() > s.length())
            return false;
        unordered_map<char, int> count;
        for (char i : s)
        {
            count[i]++;
        }

        for (char i : t)
        {
            auto it = count.find(i);
            if (it != count.end())
            {
                it->second--;
                if (it->second == 0)
                {
                    count.erase(it);
                }
            }
        }

        return count.empty();
    }
};
// @lc code=end
