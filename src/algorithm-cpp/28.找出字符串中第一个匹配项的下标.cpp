/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <string>
#include <vector>
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
        if (needle.empty())
            return 0;
        int m = haystack.size(), n = needle.size();
        vector<int> next = getNext(needle);

        int j = 0;
        for (int i = 0; i < m; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
                /* code */
            }
            if (haystack[i] == needle[j])
            {
                j++;
                /* code */
            }
            if (j == n)
                return i - n + 1;

            /* code */
        }
        return -1;
    }
    vector<int> getNext(const string &pattern)
    {
        int n = pattern.size();
        vector<int> next(n, 0);
        int j = 0;

        // 后缀的开启
        for (int i = 1; i < n; i++)
        {
            while (j > 0 && pattern[i] != pattern[j])
            {
                // 讲解A
                // 寻找前缀的上一个最长 如果匹配后续可以省略一些匹配
                // j是当前相等的前后缀
                // AB = CD / A = C则A=D
                // 我们查看next[j - 1]的相等前后缀相当于后缀部分也有一份相等的前后缀 得出A=D
                // 则我可以开始新的j开始匹配

                // 讲解B
                // 相当于获取最长相等前后缀j为对应的长度（前缀的长度）
                // 下一步是拿到前缀字符串的最长相等前后缀 因为我们计算过通过下标可以获取长度-1=》j-1
                // next 【j-1】则为我相等的前缀的最长相等先后缀的长度
                // 则前缀的前缀 = 后缀的后缀
                // 则相同的部分可以跳过匹配
                j = next[j - 1];
                /* code */
            }
            if (pattern[i] == pattern[j])
            {
                j++;
            }
            next[i] = j;
        }
        return next;
    }
};
// @lc code=end
