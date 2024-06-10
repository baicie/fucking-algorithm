/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty())
        {
            return ans;
        }
        int t = 0, b = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
        while (true)
        {
            for (int i = l; i <= r; i++)
            {
                ans.push_back(matrix[t][i]);
            }
            if (++t > b)
                break;
            for (int i = t; i <= b; i++)
            {
                ans.push_back(matrix[i][r]);
            }
            if (--r < l)
                break;
            for (int i = r; i >= l; i--)
            {
                ans.push_back(matrix[b][i]);
            }
            if (--b < t)
                break;
            for (int i = b; i >= t; i--)
            {
                ans.push_back(matrix[i][l]);
            }
            if (++l > r)
                break;
        }
        return ans;
    }
};
// @lc code=end
