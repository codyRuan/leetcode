/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        set<int> order_nums(nums.begin(), nums.end());
        int max_n = *order_nums.rbegin();
        vector<int> point(max_n+1, 0);
        for (int i = 0; i < nums.size(); i++) {
            int num = nums.at(i);
            point[num] += num;
        }
        if (nums.size() == 1) return point[nums[0]];
        point[2] = max(point[2], point[1]);
        for (int i = 3; i <= max_n; i++) {
            point[i] = max(point[i-2]+point[i], point[i-1]);
        }
        return point[max_n];
    }
};
// @lc code=end

