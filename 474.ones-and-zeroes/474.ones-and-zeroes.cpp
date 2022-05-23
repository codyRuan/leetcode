/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        for (int i = 0; i < size; i++) {
            string str = strs[i];
            int zero = count(str.begin(), str.end(), '0');
            int one = count(str.begin(), str.end(), '1');
            for (int j = 0; j <= m; j++) { // zero
                for (int k = 0; k <= n; k++) { // one
                    if (j - zero < 0 || k - one < 0) // j and k can't hold strs[i]
                        dp[i+1][j][k] = dp[i][j][k];
                    else                             // take strs[i] or not take
                        dp[i+1][j][k] = max(dp[i][j][k], dp[i][j-zero][k-one] + 1);
                }
            }
        }

        return dp[size][m][n];
    }
};
// @lc code=end

