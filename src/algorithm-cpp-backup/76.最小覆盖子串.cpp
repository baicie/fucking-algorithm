/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<char, int> ori, cnt;

    bool check()
    {
        // 校验统计结果 与现有范围
        // 如果小于期望范围不通过校验
        for (const auto &p : ori)
        {
            if (cnt[p.first] < p.second)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        // 便利数组s
        // 结果res
        //
        for (const auto &c : t)
        {
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1;

        while (r < int(s.size()))
        {
            // 获取第++r个字符
            // 如果能在目标集合中找到 将答案中++r数量+1
            if (ori.find(s[++r]) != ori.end())
            {
                ++cnt[s[r]];
            }
            // 缩小窗口
            while (check() && l <= r)
            {
                // 长度比原先的小
                if (r - l + 1 < len)
                {
                    // 更新答案
                    len = r - l + 1;
                    ansL = l;
                }
                // 找到bei缩小的窗口
                if (ori.find(s[l]) != ori.end())
                {
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? "" : s.substr(ansL, len);
    }
};
// @lc code=end
