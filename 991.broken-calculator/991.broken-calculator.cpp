/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

// @lc code=start
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
                res ++;
            }
            else {
                target ++;
                target /= 2;
                res += 2;
            }
        }
        res += (startValue-target);
        return res;
    }
};
// @lc code=end

