class MyQueue {
public:
    stack<int> st;

    void push(int x) {
        st.push(x);
    }

    int pop() {
        if (st.empty()) {
            throw runtime_error("Empty");
        }

        int top = st.top();
        st.pop();

        if (st.empty()) {
            return top;
        }

        int res = pop();
        st.push(top);
        return res;
    }

    int peek() {
        if (st.empty()) {
            throw runtime_error("Empty");
        }

        int top = st.top();
        st.pop();

        if (st.empty()) {
            st.push(top);
            return top;
        }

        int res = peek();
        st.push(top);
        return res;
    }

    bool empty() {
        return st.empty();
    }
};