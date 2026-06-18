class Solution {
public:
    bool placingIsPossible(int row, int col, vector<string> &board) {
        int r = row;
        int c = col;
        while (r >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
        }
        r = row;
        c = col;
        while (r >= 0 && c < board.size()) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }
        r = row;
        c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        return true;
    }
    void func(int row, vector<string> &board, vector<vector<string>> &ans) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (placingIsPossible(row, col, board)) {
                board[row][col] = 'Q';
                func(row + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string str(n, '.');
        for (int i = 0; i < n; i++)
            board.push_back(str);
        func(0, board, ans);
        return ans;
    }
};