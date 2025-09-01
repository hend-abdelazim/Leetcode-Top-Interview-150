class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniqueCharacters;
        int l = 0, n = s.length(), res = 0;
        for(int r = 0; r < n; r++) {
            while(uniqueCharacters.find(s[r]) != uniqueCharacters.end()) {
                uniqueCharacters.erase(s[l]);
                l++;
            }
            uniqueCharacters.insert(s[r]);
            res = max(res, r-l+1);
        }
        return res;
    }
};