/*
 Idea:
 1. once you find the target element
 2. split the array into two halves
 3. run binary search on the left side to find the left index
 4. run binary search again on the right side to find the right index
*/
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool leftSearch) {
        int l = 0, r = nums.size() - 1, mid, index = -1;
        while(l <= r) {
            mid = (l + r) / 2;
            // search for the target value until it is found
            if(nums[mid] < target) {
                l = mid + 1;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            // split the array into 2 halves
            else if (nums[mid] == target) {
                index = mid;
                if(leftSearch) { // do the right search
                    l = mid + 1; // look at the right subarray
                }
                else { // if searching the left portion is not done yet
                    r = mid - 1; // look at the left subarray
                }
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        bool leftSearch = false;
        int leftIndex = binarySearch(nums, target, leftSearch);
        leftSearch = true;
        int rightIndex = binarySearch(nums, target, leftSearch);
        return {leftIndex, rightIndex};
    }
};