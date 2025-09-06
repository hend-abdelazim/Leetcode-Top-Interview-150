class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        set<char> mappedValues;
        if(s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); i++) m[s[i]] = NULL;

        for(int i = 0; i < s.length(); i++) {
            if(m[s[i]] == NULL){
                // if the value is already mapped to another key
                if(mappedValues.find(t[i]) != mappedValues.end()) return false;
                m[s[i]] = t[i];
                mappedValues.insert(t[i]);
            }
            else if(m[s[i]] != t[i]) return false;
        }
        return true;
    }
};