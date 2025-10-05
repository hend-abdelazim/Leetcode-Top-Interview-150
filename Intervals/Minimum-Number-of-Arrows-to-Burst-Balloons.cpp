class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int number_of_arrows = 1;
        // sort by the ending point not the start point
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int end = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            // If the current interval starts after the end of the previous interval
            if(points[i][0] > end) {
                number_of_arrows++;
                end = points[i][1];
            }
        }
        return number_of_arrows;
    }
};