class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (auto it : s) {
            if (!st.empty()) {
                if (it >= 'A' && it <= 'Z' && it - 'A' == st.top() - 'a') {
                    st.pop();
                } else if (it - 'a' == st.top() - 'A') {
                    st.pop();
                } else {
                    st.push(it);
                }
            } else {
                st.push(it);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};