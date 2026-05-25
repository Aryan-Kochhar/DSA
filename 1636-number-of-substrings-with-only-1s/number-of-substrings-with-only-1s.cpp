class Solution {
public:
    int numSub(string s) {
        //n*(n+1)/2;
        long long mod = 1e9+7;
        int n = s.length();
        long long count = 0, ans = 0;
        for (char ch:s){
            if (ch == '1'){
                count++;
            }
            else{
                ans = (ans + (count*(count+1))/2 %mod ) % mod;
                count = 0;
            }
        }
        ans = (ans + (count*(count+1))/2 %mod ) % mod;
        return ans;
    }
};