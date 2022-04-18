/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = getUpdate(board, i, j);
            }
        }
        board = res;
    }
    int getUpdate(vector<vector<int>> & board, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        int livecnt = 0, target = board[row][col];

        for (int i = -1; i <= 1; i++) {
            if (row == 0 && i == -1) continue;
            if (row == m-1 && i == 1) continue;
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                if (col == 0 && j == -1) continue;
                if (col == n-1 && j == 1) continue;
                if (board[row+i][col+j] == 1) livecnt++;
            }
        }
        if (target == 1 && livecnt < 2) return 0;
        else if (target == 1 && (livecnt == 2 || livecnt == 3) ) return 1;
        else if (target == 1 && livecnt > 3) return 0;
        else if (target == 0 && livecnt == 3) return 1;
        return target;
    }   
};
// @lc code=end

