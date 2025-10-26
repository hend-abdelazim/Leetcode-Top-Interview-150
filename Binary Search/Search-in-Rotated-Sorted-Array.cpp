class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(target == nums[mid]) {
                return mid;
            }
            if(nums[mid] >= nums[l]) { // check if I stand in the left sorted portion of the array
                if(target < nums[l] || target > nums[mid])  // then if the target falls between the left and mid
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else { // if I stand in the right sorted portion of the array
                if(target < nums[mid] || target > nums[r]) // then if the target falls between the right and mid
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};