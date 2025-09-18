class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto n : nums) s.insert(n);
        int count = 1, ans = 1;
        for(auto it = s.begin(); it != s.end(); it++) {
            if(next(it) != s.end()) {
                if(abs(*it - *next(it)) == 1) {
                    count++;
                }
                else {
                    ans = max(ans, count);
                    count = 1;
                }
            }
        }
        ans = max(ans, count);
        return s.empty() ? 0 : ans;
    }
};