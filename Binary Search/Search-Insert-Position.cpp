class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (target < nums[mid]) return ceil((double)(((mid - 1) + (mid)) / 2.0));
        else return ceil((double)(((mid + 1) + (mid)) / 2.0));
    }
};