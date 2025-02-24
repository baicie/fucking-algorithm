/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int _tag = target - nums[i];
            auto it = map.find(_tag);
            if (it != map.end())
            {

                ans.push_back(it->second);
                ans.push_back(i);
                return ans;
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return ans;
    }
};
// @lc code=end
