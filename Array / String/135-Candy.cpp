class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), res = 0;
        vector<int> v(n,1);
        // verify from l to r
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1] && v[i] <= v[i-1])  {
                v[i] = v[i-1] + 1;
            }
        }
        // verify from r to l
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1] && v[i] <= v[i+1]) {
                v[i] = v[i+1] + 1;
            }
        }
        // sum up the final candy values
        for(int i : v) {
            res += i;
        }
        return res;
    }
};