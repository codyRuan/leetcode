/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), start = 0, prevdiff, res = 0;
        if (n < 3) return 0;
        for (int i = 1; i < n; i++) {
            if (i - start < 2) {
                prevdiff = nums[i] - nums[i-1];
            }
            else {
                int diff = nums[i] - nums[i-1];
                if (prevdiff == diff) continue;
                else {
                    res += count(i - start);
                    prevdiff = diff;
                    start = i-1;
                }
            }
            
        }
        if (n-start >= 3) res += count(n-start);
        return res;
    }
    
    int count(int n) {
        return (n-1)*(n-2)/2;
    }
};
// @lc code=end

