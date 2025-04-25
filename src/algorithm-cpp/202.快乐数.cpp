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
    int getNext(int n)
    {
        int total = 0;
        while (n > 0)
        {
            int digit = n % 10;
            total += digit * digit;
            n = n / 10;
            /* code */
        }
        return total;
    }
    bool isHappy(int n)
    {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n))
        {
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};
// @lc code=end
