class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> charStack;
        string temp = "";
        for (char c : s) {
            if (isalnum(c)) {
                temp += c;
                charStack.push(tolower(c));
            }
        }

        for(char c : temp) {
            if (charStack.empty() || charStack.top() != tolower(c)) {
                return false;
            }
            charStack.pop();
        }
        return true;
    }
};