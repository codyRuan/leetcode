/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') // ()
                    dp[i] = (i >= 2 ? dp[i-2] + 2 : 2);
                else if (i - dp[i-1] > 0 && s[i- dp[i-1] - 1] == '(') { // ))
                    dp[i] = dp[i-1] + (i - dp[i-1] >= 2 ? dp[i - dp[i-1] - 2] + 2 : 2);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

