/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool isMax = false;
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                swap(nums[i],nums[findMinIdx(nums, i)]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
    int findMinIdx(vector<int>& nums, int start) {
        int base = nums[start], m = INT_MAX, idx = -1;
        for (; start < nums.size(); start++) {
            if (nums[start] < m && nums[start] > base) {
                m = nums[start];
                idx = start;
            }
        }
        return idx;
    }
};
// @lc code=end

