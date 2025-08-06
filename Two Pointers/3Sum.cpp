class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int l, r;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;    // to avoid duplication
            else {
                l = i+1;
                r = nums.size() - 1;
                while(l < r) {
                    if(nums[l] + nums[r] > -(nums[i])) r--;
                    else if (nums[l] + nums[r] < -(nums[i])) l++;
                    else if (nums[l] + nums[r] == -(nums[i])) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        result.push_back(v);
                        l += 1;
                        while(nums[l] == nums[l-1] && l < r) l++;
                    }
                }
            }
        }
        return result;
    }
};