class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return -1;
        int ptr = 0;
        for(int i = 0; i < haystack.length(); i++) {
            if(haystack[i] == needle[ptr]) ptr++;
            else if(haystack[i] != needle[ptr]) {
                i -= ptr;
                ptr = 0;
            }
            if(ptr == needle.length()) return  i -=ptr-1;
        }
        return -1;
    }
};