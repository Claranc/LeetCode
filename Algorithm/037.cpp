class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        solve(board);
    }

    bool solve(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char m = '1'; m <= '9'; m++) {
                        bool falg = isValid(board, i, j, m);
                        if (falg == true) {
                            board[i][j] = m;
                            if (solve(board)) {
                                return true;
                            }
                            else {
                                board[i][j] = '.';
                            }

                        }
                    }
                    //填什么都不行返回fasle
                    return false;
                }
            }
        }
        //每个空格都填满了返回true
        return true;
    }

    bool isValid(vector<vector<char>> &board, int i, int j, int m) {
        for (int p = 0; p < 9; p++) {
            if (board[i][p] == m) {
                return false;
            }
            if (board[p][j] == m) {
                return false;
            }
            if (board[3 * (i / 3) + p / 3][3 * (j / 3) + p % 3] == m) {
                return false;
            }
        }
        return true;
    }
};