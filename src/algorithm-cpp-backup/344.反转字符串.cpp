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
        for (int i = 0; i < s.size() / 2; i++)
        {
            // 头尾对调 当大于一半就是遍历完了
            swap(s[i], s[s.size() - i - 1]);
        }
    }
};
// @lc code=end
