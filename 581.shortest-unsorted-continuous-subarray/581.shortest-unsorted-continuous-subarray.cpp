/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sml(n);
        vector<int> grt(n);
        int start = 0, end = 0;
        sml[n-1] = nums[n-1];
        grt[0] = nums[0];
        for (int i = n-2; i >= 0; i--) {
            sml[i] = min(nums[i], sml[i+1]);
        }
        for (int i = 1; i < n; i++) {
            grt[i] = max(nums[i], grt[i-1]);
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > sml[i]) {
                start = i;
                break;
            }
        }

        for (int i = n-1; i >=0 ; i--) {
            if (nums[i] < grt[i]) {
                end = i;
                break;
            }
        }
        return (end-start > 0) ? end - start + 1 : 0;
    }
};
// @lc code=end

