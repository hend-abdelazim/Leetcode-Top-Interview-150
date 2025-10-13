class Solution {
public:
    bool is_numeric(const string& s) {
        if (s.empty()) return false;
        // if the number is (+20) or (-20), start checking from index 1
        int start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
        return start < s.size() && all_of(s.begin() + start, s.end(), ::isdigit);
    }


    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for(string s : tokens) {
            if(is_numeric(s)) operands.push(stoi(s));

            else if (operands.size() >= 2) {
                int right_operand = operands.top(); operands.pop();
                int left_operand = operands.top(); operands.pop();

                if (s == "+") operands.push(left_operand + right_operand);
                else if (s == "-") operands.push(left_operand - right_operand);
                else if (s == "*") operands.push(left_operand * right_operand);
                else if (s == "/") operands.push(left_operand / right_operand);
            }
        }
        return operands.top();
    }
};