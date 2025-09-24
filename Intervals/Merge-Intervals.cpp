class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0, start, end;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        while(i < intervals.size()) {
            start = intervals[i][0];
            end = intervals[i][1];
            while(i < intervals.size() - 1 && intervals[i+1][0] <= end) {
                i++;
                end = max(end, intervals[i][1]);
            }
            ans.push_back({start, end});
            i++;
        }
        return ans;
    }
};