class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0, start;
        while(i < nums.size()) {
            start = nums[i];
            while( i < nums.size() - 1 && (nums[i] + 1 == nums[i+1])) {
                i++;
            }
            if(start == nums[i]) {
                ans.push_back(to_string(nums[i]));
            }
            else {
                string s = to_string(start) + "->" + to_string(nums[i]);
                ans.push_back(s);
            }
            i++;
        }
        return ans;
    }
};