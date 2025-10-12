class MinStack {
public:
    stack<int> st;
    stack<int> min_stack;
    int minVal;
    MinStack() {
        stack<int> st = stack<int>();
        stack<int> min_stack = stack<int>();
    }

    void push(int val) {
        st.push(val);
        if(min_stack.empty()) minVal = val;
        else minVal = min(val, min_stack.top());
        min_stack.push(minVal);
    }

    void pop() {
        st.pop();
        min_stack.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_stack.top();
    }
};