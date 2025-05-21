/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtrack(k, n, 1, 0);
        return res;
    }

    void backtrack(int k, int n, int start, int sum)
    {
        if (path.size() == k)
        {
            if (sum == n)
            {
                res.push_back(path);
            }
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            if (sum + i > n)
                break;

            path.push_back(i);
            backtrack(k, n, i + 1, sum + i);
            path.pop_back();
        }
    }
};
// @lc code=end
