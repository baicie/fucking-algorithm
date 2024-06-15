/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1, set2;
        for (auto &num : nums1)
        {
            set1.insert(num);
        }
        for (auto &num : nums2)
        {
            set2.insert(num);
        }

        return set1.size() > set2.size() ? getIntersection(set2, set1) : getIntersection(set1, set2);
    }

    vector<int> getIntersection(unordered_set<int> &set1, unordered_set<int> &set2)
    {
        vector<int> ans;
        for (auto &num : set1)
        {
            if (set2.count(num))
            {
                ans.push_back(num);
            }
        }

        return ans;
    }
};
// @lc code=end
