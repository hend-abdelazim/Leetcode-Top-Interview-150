class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, sz = intervals.size(), start, end;
        bool included = false;
        vector<vector<int>> ans;
        while(i < sz) {
            start = intervals[i][0];
            end = intervals[i][1];
            // insert in the beginning
            if(newInterval[0] < start && newInterval[1] < start && !included) {
                ans.push_back({newInterval[0], newInterval[1]});
                included = true;
            }
            
            else if(newInterval[0] <= end && !included) {
                start = min(newInterval[0], start);
                end = max(newInterval[1], end);
                while(i < sz - 1 && intervals[i+1][0] <= end) {
                    start = min(intervals[i+1][0], start);
                    end = max(intervals[i+1][1], end);
                    i++;
                }
                included = true;
            }
            ans.push_back({start, end});
            i++;
        }
        if(ans.empty() || !included) ans.push_back({newInterval[0], newInterval[1]});
        return ans;
    }
};