/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(m+1,0));
        vector<int> presum(n+1, 0);

        for (int i = 0; i < n; i++) 
            presum[i+1] = presum[i] + nums[i];

        for (int cutnum = 1; cutnum <= m; cutnum++) {
            for (int start = 0; start < n; start++) {
                if (cutnum == 1) { // base
                    dp[start][cutnum] = presum[n] - presum[start];
                }
                else {
                    int minsum = INT_MAX;
                    for (int i = start; i <= n-cutnum; i++) {
                        int leftsum = presum[i+1] - presum[start];
                        int maxsum = max(leftsum, dp[i+1][cutnum-1]);
                        minsum = min(maxsum, minsum);
                    }
                    dp[start][cutnum] = minsum;
                }   
            }
        }
        return dp[0][m];
    }
};
// @lc code=end

