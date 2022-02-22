/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int N = 26;
        int sum = 0;
        int ascii = int('A')-1;
        reverse(columnTitle.begin(), columnTitle.end());
        for (int i = 0; i < columnTitle.size(); i++){
            sum += (int(columnTitle[i]) - ascii) * pow(N,i);
        }
        return sum;
    }
};
// @lc code=end

