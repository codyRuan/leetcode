/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int conti = 0;
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            if (i != nums.size()-1) {
                int next = nums[i+1];
                if (next == curr+1) conti++;
                else {
                    if (!conti) { 
                        res.push_back(to_string(nums[i]));
                    }
                    else {
                        string s = to_string(nums[i-conti]);
                        s+="->";
                        s+=to_string(nums[i]);
                        res.push_back(s);
                        conti = 0;
                    }
                }
            }
            else {
                if (!conti) { 
                    res.push_back(to_string(nums[i]));
                }
                else {
                    res.push_back(to_string(nums[i-conti])+"->"+to_string(nums[i]));
                    conti = 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end

