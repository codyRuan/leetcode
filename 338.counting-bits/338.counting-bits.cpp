/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        int exp_2 = 1;
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= n; i++) {
            int threshold = 1 << exp_2;
            int prvhold = 1 << (exp_2-1);
            if (i == threshold-1) res.push_back(exp_2);
            else if (i < threshold) res.push_back(1+res[i-prvhold]);
            else {
                res.push_back(1);
                exp_2++;
            }
        }
        return res;
    }
};
// @lc code=end

