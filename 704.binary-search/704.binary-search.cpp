/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size()-1);
    }

    int binary_search(vector<int> &nums, int target, int left, int right) {
        if (left == right && nums[left] != target) return -1;
        int mid_idx = (left+right)/2;
        int mid = nums[mid_idx];
        if (mid == target) return mid_idx;
        else if (mid > target) return binary_search(nums, target, left, mid_idx);
        else return binary_search(nums, target, mid_idx+1, right);
    }
};
// @lc code=end

