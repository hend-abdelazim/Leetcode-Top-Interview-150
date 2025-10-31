class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0], l = 0, r = nums.size() - 1, mid;
        while(l <= r) {
            if (nums[l] < nums[r]) { // then the array is already sorted and not rotated
                res = min(res, nums[l]);
                break;
            }
            else {
                mid = (l + r) / 2;
                res = min(res, nums[mid]);
                /* I am standing on the left sorted portion and the array is rotated
                 * cause nums[r] < nums[l]
                 * ,so I have to search in the right sorted portion*/
                if(nums[mid] >= nums[l]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return res;
    }
};