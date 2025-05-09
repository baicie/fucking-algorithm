/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
private:
    vector<vector<string>> result;
    vector<string> path;               // 放已经回文的子串
    vector<vector<bool>> isPalindrome; // 放事先计算好的是否回文子串的结果
    void backtracking(const string &s, int startIndex)
    {
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome[startIndex][i])
            { // 是回文子串
                // 获取[startIndex,i]在s中的子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
            { // 不是回文，跳过
                continue;
            }
            backtracking(s, i + 1); // 寻找i+1为起始位置的子串
            path.pop_back();        // 回溯过程，弹出本次已经添加的子串
        }
    }
    void computePalindrome(const string &s)
    {
        // isPalindrome[i][j] 代表 s[i:j](双边包括)是否是回文字串
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false)); // 根据字符串s, 刷新布尔矩阵的大小
        for (int i = s.size() - 1; i >= 0; i--)
        {
            // 需要倒序计算, 保证在i行时, i+1行已经计算好了
            for (int j = i; j < s.size(); j++)
            {
                if (j == i)
                {
                    isPalindrome[i][j] = true;
                }
                else if (j - i == 1)
                {
                    isPalindrome[i][j] = (s[i] == s[j]);
                }
                else
                {
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
                }
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        result.clear();
        path.clear();
        computePalindrome(s);
        backtracking(s, 0);
        return result;
    }
};

// @lc code=end
