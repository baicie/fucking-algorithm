/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    void backtrack(const vector<int> &candidates, int target, int start)
    {
        if (target == 0)
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
            {
                continue;
            }
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtrack(candidates, target, 0);
        return result;
    }
};
// @lc code=end
