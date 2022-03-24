/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(), people.end());
        int back = people.size()-1, front = 0;
        while (back >= front) {
            int target = people[back];
            int mini = people[front];
            if (target + mini <= limit) front++;
            back--;
            res++;
        }
        return res;
    }
};
// @lc code=end

