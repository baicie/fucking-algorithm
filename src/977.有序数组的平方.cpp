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
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
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
                ans.push_back(square(nums[j++]));
            }
            else if (j == n)
            {
                ans.push_back(square(nums[i--]));
            }
            else if (square(nums[i]) < square(nums[j]))
            {
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
