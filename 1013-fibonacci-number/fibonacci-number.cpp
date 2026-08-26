class Solution {
public:
    // int fib(int n) {
    //     if (n==0) return 0;
    //     if (n==1) return 1;
    //     vector<int> dp(n+1,-1);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     for (int i=2;i<=n;i++){
    //         dp[i] = dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }
    
    int fib(int n){
        if (n==0) return 0;
        if (n==1) return 1;
        int first = 0, second = 1;
        int third = first+second;
        for (int i=1;i<n;i++){
            third = first+second;
            first = second;
            second = third;
        }
        return third;
    }
};