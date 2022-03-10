/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cup (query_row+1, vector<double>(query_row+1));
        cup[0][0] = poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double spilt = (cup[i][j] - 1) / 2;
                if (spilt > 0) {
                    cup[i+1][j] += spilt;
                    cup[i+1][j+1] += spilt;
                }
            }
        }
        return min(1.0, cup[query_row][query_glass]);
    }
};
// @lc code=end

