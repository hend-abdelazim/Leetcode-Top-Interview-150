class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream stream(s);
        string word;
        while(stream >> word) words.push_back(word);
        if(words.size() != pattern.length()) return false;
        
        map<char, string> m1;
        map<string, char> m2;
        for(int i = 0; i < pattern.length(); i++) {
            m1[pattern[i]] = "";
            m2[words[i]] = NULL;
        }
        for(int i = 0; i < pattern.length(); i++) {
            if(m1[pattern[i]] == "" && m2[words[i]] == NULL) {
                m1[pattern[i]] = words[i];
                m2[words[i]] = pattern[i];
            }
            else if(m1[pattern[i]] != words[i]) return false;
        }
        return true;
    }
};