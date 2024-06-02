/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long long l = 0, r = num;

        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            long long mids = mid * mid;
            if (mids == num)
            {
                return true;
            }
            else if (mids < num)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return false;
    }
};
// @lc code=end
