class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) m[nums[i]] = i;
        for(int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if(m.find(temp) != m.end() && m[temp] != i) {
                ans.push_back(i);
                ans.push_back(m[temp]);
                break;
            }
        }
        return ans;
    }
};