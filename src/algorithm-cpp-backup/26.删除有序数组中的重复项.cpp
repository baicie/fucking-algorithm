/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        // 使用快慢指针
        // 因为fast指针进行判断 所以从1开始
        // 当与前一个值不相同的时候 将fast位置赋予slow位置并前移
        // 这样既可去除重复的元素 因为相同的时候fast前移 slow不动
        // slow即为不同项的长度
        int slow = 1;
        for (int fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast - 1] != nums[fast])
            {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
// @lc code=end
