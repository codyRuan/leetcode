/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return true;

            if (nums[mid] == nums[start]) {
                start++;
                continue;
            }
            bool midArray = (nums[start] <= nums[mid]);
            bool targetArray = (nums[start] <= target);
            if (midArray ^ targetArray) { // target and mid are in different array
                if (midArray) start = mid + 1; // target in the second
                else end = mid - 1; // target in the first
            }
            else { // target and mid are in same array
                if (nums[mid] < target) start = mid + 1; 
                else end = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

