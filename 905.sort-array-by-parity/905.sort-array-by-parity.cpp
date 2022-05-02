/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0, k = nums.size()-1;
        while (j < k) {
            if (nums[j] % 2 > nums[k] % 2)
                swap(nums[j], nums[k]);
            if (nums[j] % 2 == 0) j ++;
            if (nums[k] % 2 == 1) k --;
        }
        return nums;
    }
};
// @lc code=end

