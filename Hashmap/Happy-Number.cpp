class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int value;
        int digit;
        while(true) {
            value = 0;
            while(n) {
                digit = n % 10;
                value += digit * digit;
                n = n / 10;
            }
            if(value == 1) return true;
            else if(s.find(value) != s.end()) return false;  // if it already exists
            s.insert(value);
            n = value;
        }
        return false;
    }
};