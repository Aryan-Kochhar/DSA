class Solution {
public:
    int minSwaps(string s) {
        //stack<char> st;
        //st.push('X');
        int count=0;
        int open=0;
        for (char &ch : s){
            if (ch=='[') open++;
            else if (ch==']' && open>0) open--;
            else count++;
        }
        return (int)((count+1)/2);
    }
};