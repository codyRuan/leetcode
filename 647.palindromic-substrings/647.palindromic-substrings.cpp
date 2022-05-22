/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n-1-i]) return false;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) dp[i][j] = 1;
                else if (j - i == 1) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += dp[i][j];
            }
        }

        return res;
    }
};
// @lc code=end

