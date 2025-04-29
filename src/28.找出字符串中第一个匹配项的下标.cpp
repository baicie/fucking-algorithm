/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // 前面匹配过相当于是一样的
        // 随后找到前面匹配过的字符串的最大相等前后缀 意味着原字符串中也有个相等前后缀的子串
        // 因为前后相同我就不用匹配hasystack的后面几位 因为和needle的前面几位相同
        // 只需要移动到对应的冲突的字符开始匹配
    }
};
// @lc code=end
