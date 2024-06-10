/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int t = 0, b = n - 1, l = 0, r = n - 1;
        int num = 1, tar = n * n;
        vector<vector<int>> ans(n, vector<int>(n));
        while (num <= tar)
        {
            for (int i = l; i <= r; i++)
            {
                ans[t][i] = num++;
            }
            t++;
            for (int i = t; i <= b; i++)
            {
                ans[i][r] = num++;
            }
            r--;
            for (int i = r; i >= l; i--)
            {
                ans[b][i] = num++;
            }
            b--;
            for (int i = b; i >= t; i--)
            {
                ans[i][l] = num++;
            }
            l++;
        }

        return ans;
    }
};
// @lc code=end
