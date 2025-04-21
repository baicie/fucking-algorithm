/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        // 使用快慢指针
        // 当值与快指针不同将值赋予慢指针的位置
        // 当出现val值时快指针比慢指针走的步数多
        // 返回slow即为当前数组不同于slow的数量
        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (val != nums[fast])
            {
                nums[slow++] = nums[fast];
            }
        }

        return slow;
    }
};
// @lc code=end
