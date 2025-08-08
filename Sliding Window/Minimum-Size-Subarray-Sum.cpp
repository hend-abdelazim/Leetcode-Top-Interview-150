class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, minLen = INT_MAX, sum = nums[0];
        while (l <= r && r < nums.size()) {
            if(sum < target) {
                r++;
                if(r < nums.size()) sum += nums[r];
            }
            else if(sum >= target) {
                minLen = min(minLen, r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};