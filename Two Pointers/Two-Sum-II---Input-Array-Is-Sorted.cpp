class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            if(numbers[l] + numbers[r] > target) r--;
            else if(numbers[l] + numbers[r] < target) l++;
            else {
                result.push_back(l+1);
                result.push_back(r+1);
                break;
            }
        }
        return result;
    }
};