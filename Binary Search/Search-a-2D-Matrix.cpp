class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), columns = matrix[0].size();
        int r = 0, left, right, mid;
        while(r < rows) {
            if(target <= matrix[r][columns - 1]) {
                left = 0, right = columns - 1;
                while(left <= right) {
                    mid = (left + right) / 2;
                    if(target == matrix[r][mid]) 
                        return true;
                    else if(target < matrix[r][mid])
                        right = mid - 1;
                    else 
                        left = mid + 1;
                }
            }
            r++;
        }
        return false;
    }
};