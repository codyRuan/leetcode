/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    void perm(vector<vector<int>> &res, int idx, vector<int> nums) {
        if (idx == nums.size()-1) {res.push_back(nums); return;}
        for (int i = idx; i < nums.size(); i++) {
            if (i == idx || nums[i] != nums[idx]){
                swap(nums[i], nums[idx]);
                perm(res, idx+1, nums);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        perm(res, 0, nums);
        return res;
    }
};
// @lc code=end

