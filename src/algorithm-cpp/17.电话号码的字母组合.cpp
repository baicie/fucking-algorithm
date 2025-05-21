/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> res;
    string path;
    unordered_map<char, string> phone = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        backtrack(digits, 0);
        return res;
    }

    void backtrack(const string &digits, int index)
    {
        if (index == digits.size())
        {
            res.push_back(path);
            return;
        }

        string letters = phone[digits[index]];
        for (char ch : letters)
        {
            path.push_back(ch);
            backtrack(digits, index + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
