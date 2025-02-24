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
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int tartget, int k, int sum, int startIndex)
    {
        if (path.size() == k)
        {
            if (sum == tartget)
            {
                result.push_back(path);
            }
            return;
        }
        for (int i = startIndex; i <= 9; i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(tartget, k, sum, i + 1);
            sum -= i;
            path.pop_back();
            /* code */
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(n, k, 0, 1);
        return result;
    }
};
// @lc code=end
