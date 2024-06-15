/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> map1;
        for (auto &num : nums1)
        {
            map1[num]++;
        }
        vector<int> ans;

        for (int num : nums2)
        {
            if (map1.count(num))
            {
                ans.push_back(num);
                map1[num]--;
                if (map1[num] == 0)
                {
                    map1.erase(num);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
