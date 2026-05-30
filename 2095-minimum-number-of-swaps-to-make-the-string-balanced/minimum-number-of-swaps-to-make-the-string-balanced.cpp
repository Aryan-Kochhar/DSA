class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        st.push('X');
        int count=0;
        for (char &ch : s){
            if (ch=='[') st.push(ch);
            else if (ch==']' && st.top()=='[') st.pop();
            else count++;
        }
        return (int)((count+1)/2);
    }
};