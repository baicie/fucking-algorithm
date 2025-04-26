/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            /* code */
            left++;
            right--;
        }
    }
};
// @lc code=end
