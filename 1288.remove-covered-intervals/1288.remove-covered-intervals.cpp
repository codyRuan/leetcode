/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> criteria = intervals[0];
        int numOfDel = 0;
        for (int  i = 1; i < intervals.size(); i++){
            vector<int> obj = intervals[i];
            if (criteria[0] == obj[0]){
                if (criteria[1] < obj[1])
                    criteria = obj;
                numOfDel++;
            }
            else if (criteria[1] >= obj[1])
                numOfDel++;
            else
                criteria = obj;
        }
        return intervals.size() - numOfDel;
    }
    static bool cmp(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }
};
// @lc code=end

