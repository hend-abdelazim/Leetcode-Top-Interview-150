class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        int blocks[3][3][10] = {0};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(isdigit(board[i][j])) {
                    if(rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || blocks[i/3][j/3][board[i][j] - '0'] != 0) {
                        return false;
                    }
                    else {
                        rows[i].insert(board[i][j]);
                        cols[j].insert(board[i][j]);
                        blocks[i/3][j/3][board[i][j] - '0'] = board[i][j] - '0';
                    }
                }
            }
        }
        return true;
    }
};