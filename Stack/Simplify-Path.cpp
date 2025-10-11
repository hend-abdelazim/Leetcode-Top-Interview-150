class Solution {
public:
    string simplifyPath(string path) {
        vector<string> files;
        stringstream ss(path);
        string file;
        char del = '/';
        while(getline(ss, file, del)) {
            files.push_back(file);
        }

        stack<string> st;
        for(const string& f : files) {
            if(f == "." || f.empty()) continue;
            else if(f == ".." && !st.empty()) st.pop();
            else if(f != "..") st.push(f);
        }
        
        vector<string> revered_path;
        while(!st.empty()) {
            revered_path.push_back(st.top());
            st.pop();
        }
        reverse(revered_path.begin(), revered_path.end());
        
        string ans = "/";
        for(int i = 0; i < revered_path.size(); i++) {
            ans += revered_path[i];
            if(i != revered_path.size() - 1) ans += "/";
        }
        return ans;
    }
};