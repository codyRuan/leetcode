/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second > b.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        vector<pair<int,int>> vec;
        vector<int> res;
        for (int n : nums) m[n]++;
        for (auto &itr : m) vec.push_back(itr);
        sort(vec.begin(), vec.end(), cmp); 
        for (auto itr = vec.begin(); itr != vec.begin()+k; itr++)
            res.push_back(itr->first);
        return res;
    }
};
// @lc code=end

