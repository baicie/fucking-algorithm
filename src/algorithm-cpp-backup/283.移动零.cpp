/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0, fast = 0, length = nums.size();
        while (fast < length)
        {
            // 如果值有效 不为0 则将快慢置换 慢右移
            if (nums[fast])
            {
                swap(nums[slow++], nums[fast]);
            }
            fast++;
        }
    }
};
// @lc code=end
