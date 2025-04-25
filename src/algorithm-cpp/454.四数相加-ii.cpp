/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> sumAB;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                sumAB[a + b]++;
                /* code */
            }

            /* code */
        }

        int count = 0;
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                int target = -(c + d);
                if (sumAB.count(target))
                {
                    count += sumAB[target];
                }
            }
            /* code */
        }
        return count;
    }
};
// @lc code=end
