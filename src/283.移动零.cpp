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
            if (nums[fast])
            {
                swap(nums[slow++], nums[fast]);
            }
            fast++;
        }
    }
};
// @lc code=end
