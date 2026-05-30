class Solution {
public:
    string reverseParentheses(string s) {
        string result = "";
        stack<int> lastSkipLength;
        for (char &ch:s){
            if (ch=='('){
                lastSkipLength.push(result.length());
            }
            else if (ch==')'){
                int l = lastSkipLength.top();
                lastSkipLength.pop();
                reverse(begin(result)+l,end(result));
            } else result.push_back(ch);
        };
        return result;
    }
};