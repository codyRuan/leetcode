/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum= 0, n = nums.size();
        
        for (int num : nums) {
            sum += num;
        }

        return n * (n + 1) / 2 - sum;
    }
};
// @lc code=end

