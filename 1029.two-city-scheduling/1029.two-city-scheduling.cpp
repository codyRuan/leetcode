/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] - a[0] > b[1] - b[0];
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0, n = costs.size();
        sort(costs.begin(), costs.end(), cmp);
        for (int i = 0; i < n/2; i++) res += costs[i][0];
        for (int i = n/2; i < n; i++) res += costs[i][1];
        return res;
    }
    
};
// @lc code=end

