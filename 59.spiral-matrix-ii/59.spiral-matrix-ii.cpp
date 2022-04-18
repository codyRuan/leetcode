/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        vector<int> step;
        int dir = 0, count = 0; 
        int x = 0, y = 0;
        step.push_back(n-1);
        for (int i = n-1; i > 0; i--) {
            step.push_back(i);
            step.push_back(i);
        }
        step.push_back(1);
        for (auto s : step) {
            for (int i = 0; i < s; i++) {
                res[x][y] = ++count;
                updateDir(dir, x, y);
            }
            dir++;
        }
        return res;
    }
    void updateDir(int dir, int &x, int &y) {
        if (dir % 4 == 0) y++; // right 
        else if (dir % 4 == 1) x++; // down
        else if (dir % 4 == 2) y--; // left
        else x--; // up
    }
};
// @lc code=end

