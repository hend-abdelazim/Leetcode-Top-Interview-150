class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int sz = s.size();
        for(char c : t) {
            if(c == s[i] && i < sz)
                i++;
        }
        if(i == sz)
            return true;
    return false;
    }
};