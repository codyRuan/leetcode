/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int p3 = INT_MIN;
        vector<int> stk;
        for (auto itr = nums.rbegin(); itr != nums.rend(); itr++) {
            if (*itr < p3) return true;
            else while (!stk.empty() && *itr > stk.back()) {
                p3 = stk.back();
                stk.pop_back();
            }
            stk.push_back(*itr);
        }
        return false;
    }
};
// @lc code=end

