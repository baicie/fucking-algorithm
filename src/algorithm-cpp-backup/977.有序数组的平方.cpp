/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int neg = -1;
        int n = nums.size();
        // 找到对应的中分
        // 递增的序列了算是 -1 0 0 1 2
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                // 找最接近0的下标 当全为大于等于0的数字 -1开始
                neg = i;
            }
            else
            {
                break;
            }
        }

        vector<int> ans;
        int i = neg, j = neg + 1;
        while (i >= 0 || j < n)
        {
            if (i < 0)
            {
                // 前半截遍历完了 后半截存
                ans.push_back(square(nums[j++]));
            }
            else if (j == n)
            {
                // 后半截遍历完了 前半截存
                ans.push_back(square(nums[i--]));
            }
            else if (square(nums[i]) < square(nums[j]))
            {
                // 判断大小了
                ans.push_back(square(nums[i--]));
            }
            else
            {
                ans.push_back(square(nums[j++]));
            }
        }

        return ans;
    }
    int square(int a)
    {
        return a * a;
    }
};
// @lc code=end
