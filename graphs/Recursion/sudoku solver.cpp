https://leetcode.com/problems/sudoku-solver/submissions/1873612754/

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;//checkin rows
            if (board[i][col] == ch) return false;//chweckin col
        }
//to get thstart r,c of each 3*3 group
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;

//checkin the 3*3 box groups
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {//for empty char
                    for (char ch = '1'; ch <= '9'; ch++) {//check all chr from 1 to 9
                        if (isValid(board, row, col, ch)) {
                            board[row][col] = ch;
                            if (solve(board)) return true;
                            board[row][col] = '.';//backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
