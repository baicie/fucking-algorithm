/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int result = 0, left = 0;
        int n = fruits.size();
        unordered_map<int, int> subM;
        for (int right = 0; right < n; right++)
        {
            // 先进行计数
            ++subM[fruits[right]];
            // 水果大于2 要进行减少操作
            while (subM.size() > 2)
            {
                auto it = subM.find(fruits[left]);
                --it->second;
                if (it->second == 0)
                {
                    // -到0进行移除
                    subM.erase(it);
                }
                // 每次左指指针右移
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end
