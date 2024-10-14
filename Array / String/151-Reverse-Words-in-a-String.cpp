class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string word = "", res = "";
        for(int i = s.length()-1; i >= 0; i--) {
            if(s[i] != ' ') {
                word += s[i];
            }
            else if(s[i] == ' ' && word.length() > 0){
                reverse(word.begin(), word.end());
                v.push_back(word);
                word = "";
            }
        }
        if(word.length() > 0) {
            reverse(word.begin(), word.end());
            v.push_back(word);
        }
        res += v[0];
        for(int i = 1; i < v.size(); i++){
            res += ' ';
            res += v[i];
        }
        return res;
    }
};