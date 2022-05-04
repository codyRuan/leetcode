/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        int r = 0, l = n-1;
        sort(nums.begin(), nums.end());
        while (r < l) {
            if (nums[r] + nums[l] == k) {
                r++; l--;
                res++;
            }
            else if (nums[r] + nums[l] > k)
                l--;
            else 
                r++;
        }
        return res;
    }
};
// @lc code=end

