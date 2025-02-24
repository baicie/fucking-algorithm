/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    vector<int> combination;
    vector<vector<int>> result;

public:
    void backtrack(vector<int> candidates, int target, int start)
    {
        if (target == 0)
        {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            /* code */
            if (candidates[i] > target)
            {
                break;
            }
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return result;
    }
};
// @lc code=end
