/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while (true)
        {
            int sum = getHappy(n);
            if (sum == 1)
            {
                return true;
            }

            if (set.find(sum) != set.end())
            {
                return false;
            }
            else
            {
                set.insert(sum);
            }

            n = sum;
        }
    }

    int getHappy(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
// @lc code=end
