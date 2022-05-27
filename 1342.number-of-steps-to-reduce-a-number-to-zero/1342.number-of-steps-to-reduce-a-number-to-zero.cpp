/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps(int num) {
        if (!num) return 0;

        int res = 0;

        while (num) {
            res += num & 1 ? 2 : 1;
            num >>= 1;
        }

        return res-1;
    }
};
// @lc code=end

