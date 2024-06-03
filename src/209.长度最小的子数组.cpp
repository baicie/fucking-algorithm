/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = __INT32_MAX__;
        int sum = 0;
        int i = 0;
        int subLength = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                subLength = j - i + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[i++];
            }
        }

        return result == __INT32_MAX__ ? 0 : result;
    }
};
// @lc code=end
