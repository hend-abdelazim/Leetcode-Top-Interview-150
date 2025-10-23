/* Solution idea:
 * 1. check for the mid -> if it's a peak element then -> kheer w baraka
 * 2. if the mid is not a peak element then it has at least one neighbour that is greater than it
 * 3. go for the greater element side as -> this element is either has a lower value on their other side -> then it is a peak element
 * or this other half is sorted in an increasing order which means it is guaranteed that the last element will be a peak element
 * */
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r) {
            mid = (l+r) / 2;
            if((mid > 0 && nums[mid- 1] > nums[mid])) {
                r = mid - 1;
            }
            else if( mid < nums.size()-1 && nums[mid+1] > nums[mid]) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }
        return mid;
    }
};