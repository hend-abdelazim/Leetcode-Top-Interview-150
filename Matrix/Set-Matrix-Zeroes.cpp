class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0 = 1;

        // traverse the matrix to mark the rows and cols of zeros inplace
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    // mark the row
                    matrix[i][0] = 0;
                    // mark the column
                    if(j != 0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }
        // convert the marked rows and cols to zeros excepts the first one
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // re-check for the first row
        if(matrix[0][0] == 0)
            for(int j = 0; j < cols; j++) matrix[0][j] = 0;
        // re-check for the first col
        if(col0 == 0)
            for(int i = 0; i < rows; i++) matrix[i][0] = 0;
    }
};