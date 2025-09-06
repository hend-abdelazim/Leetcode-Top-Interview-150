int countNeighbours(int r, int c, int rows, int cols, vector<vector<int>>& board) {
    int count = 0;
    // check the 8 neighbours of the current cell(r, c)
    for(int i = r-1; i <= r+1; i++) {
        for(int j = c-1; j <= c+1; j++) {
            // skip the current cell itself and invalid indices
            if((i == r && j == c) || i < 0 || j < 0 || i >= rows || j >= cols ) continue;
            else if(board[i][j] == 3 || board[i][j] == 1) count++;  // 3 or 1 means it was originally = 1
        }
    }
    return count;
}

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0  -> 0  | 0
        // 1  -> 0  | 1
        // 0  -> 1  | 2
        // 1  -> 1  | 3
        int rows = board.size();
        int cols = board[0].size();

        // Encoding phase
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int cnt = countNeighbours(i, j, rows, cols, board);
                if(board[i][j] && (cnt == 2 || cnt == 3)) board[i][j] = 3;
                else if (!board[i][j] && cnt == 3) board[i][j] = 2;
            }
        }
        // Decoding phase
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 2 || board[i][j] == 3) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};