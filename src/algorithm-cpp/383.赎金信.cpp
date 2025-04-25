/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> magazineCount;
        for (char c : magazine)
        {
            magazineCount[c]++;
        }

        for (char c : ransomNote)
        {
            if (magazineCount[c] > 0)
            {
                magazineCount[c]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
