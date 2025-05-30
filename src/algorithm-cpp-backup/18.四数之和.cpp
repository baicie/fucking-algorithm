/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] > target && nums[k] >= 0)
            {
                break;
            }

            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }

            for (int i = k + 1; i < nums.size(); i++)
            {
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
                {
                    break;
                }

                if (i > k + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }

                int left = i + 1, right = nums.size() - 1;
                while (right > left)
                {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back(
                            vector<int>{nums[k], nums[i], nums[left], nums[right]});

                        while (right > left && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        while (right > left && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
