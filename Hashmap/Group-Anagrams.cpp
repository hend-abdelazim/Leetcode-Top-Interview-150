class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string, vector<int>> m;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            m[word].push_back(i);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            vector<string> temp;
            for (auto index: it->second) {
                temp.push_back(strs[index]);
            }
            result.push_back(temp);
        }
        return result;
    }
};