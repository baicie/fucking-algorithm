/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        // 当前总和
        int sum = 0;
        // 窗口的长度
        int subLenght = 0;
        // 窗口坐标
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            /* code */
            sum += nums[fast];
            while (sum >= target)
            {
                subLenght = fast-slow+1;
                result=result < subLenght ? result : subLenght;
                sum -= nums[slow++];
            }
            
        }
        return result == INT32_MAX ? 0:result; 
    }
};
// @lc code=end

