/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int len = s.size();
        for (int i = 0; i < len; i += 2 * k)
        {
            int left = i;
            int right = min(i + k - 1, len - 1);
            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};
// @lc code=end
