class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    vector<int> col, diag1, diag2;

    void backtrack(int r, int n) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[r + c] || diag2[r - c + n - 1]) 
                continue;

            col[c] = diag1[r + c] = diag2[r - c + n - 1] = 1;
            board[r][c] = 'Q';

            backtrack(r + 1, n);

            board[r][c] = '.';
            col[c] = diag1[r + c] = diag2[r - c + n - 1] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        col.assign(n, 0);
        diag1.assign(2 * n, 0);
        diag2.assign(2 * n, 0);

        board.assign(n, string(n, '.'));

        backtrack(0, n);
        return res;
    }
};
