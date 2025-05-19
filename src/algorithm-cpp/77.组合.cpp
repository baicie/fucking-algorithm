/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(int n, int k, int start)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }

        // 剪枝：i <= n - (k - path.size()) + 1
        // n - i + 1 >= k - path.size()
        // 4 - 1 = 3但是不包括当前的数所以需要+1
        for (int i = start; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            backtrack(n, k, i + 1); // 递归
            path.pop_back();        // 回溯
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backtrack(n, k, 1);
        return result;
    }
};
// @lc code=end
