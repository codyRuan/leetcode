/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (count == 0)
                candidate = nums[i];
            count += (candidate == nums[i]) ? 1 : -1;
        }
        return candidate;
    }
};
// @lc code=end

