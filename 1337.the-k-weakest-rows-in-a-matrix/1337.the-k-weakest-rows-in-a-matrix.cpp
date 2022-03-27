/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<int> candidate;
        map<int,vector<int>> order;
        vector<int> res;
        for (int i = 0; i < mat.size(); i++) {
            int ones = 0;
            auto row = mat[i];
            for (auto o : row) {
                if (o == 1) ones++;
            }
            candidate.insert(ones);
            order[ones].push_back(i);
        }
        for (auto candi : candidate) {
            for (auto idx : order[candi]) res.push_back(idx);
        }
        vector<int> tmp(res.begin(), res.begin()+k);
        return tmp;
    }
};
// @lc code=end

