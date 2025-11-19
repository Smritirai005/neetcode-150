class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) return false;        // row
            if (board[i][c] == ch) return false;        // col
            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == ch) return false; // box
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {

                        if (isValid(board, r, c, ch)) {
                            board[r][c] = ch;

                            if (solve(board)) return true;

                            board[r][c] = '.'; // backtrack
                        }
                    }
                    return false; // none worked
                }
            }
        }
        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
