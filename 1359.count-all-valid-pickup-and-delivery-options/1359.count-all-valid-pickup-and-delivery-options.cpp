/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
class Solution {
public:
    int countOrders(int n) {
        long res = 1;
        int m = 1000000007;
        for (int i = 1; i <= 2*n; i++) {
            res = (res * i);
            if (i % 2 == 0) res /= 2;
            res %= m;
        }
        return res;
    }
};
// @lc code=end

