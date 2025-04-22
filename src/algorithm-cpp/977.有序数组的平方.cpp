/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) { 
        int index = nums.size() - 1;
        vector<int> result(nums.size(),0);
        for (int left = 0,right = nums.size() -1; left <= right;)
        {
            /* code */
            int leftS = square(nums[left]);
            int rightS = square(nums[right]);
            if(leftS > rightS){
                result[index--] = leftS;
                left++;
            }else{
                result[index--] = rightS;
                right --;
            }
        }
        return result;
    }
    int square(int a)
    {
        return a * a;
    }
};
// @lc code=end

