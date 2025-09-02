class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // To rotate a matrix by 90ْ :
        // 1- transpose the matrix
        unsigned long long n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 2- reverse each row of the matrix
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};