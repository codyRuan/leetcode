/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
    void recursive(vector<vector<int>>& res, vector<int>& stk, int k, int n) {
        if (stk.size() == k && n == 0) {
            res.push_back(stk);
            return;
        }
        for (int i = stk.empty() ? 1 : stk.back()+1; i <= 9; i++) {
            stk.push_back(i);
            recursive(res, stk, k, n - i);
            stk.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> stk;
        recursive(res, stk, k, n);
        return res;
    }
};
// @lc code=end

