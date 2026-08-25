class Solution {
public:
    //memoization:
    // int solve(int i,int j,int n,int m,vector<vector<int>> &dp,vector<vector<int>> &arr){
    //     if (j<0 || j>=m) return 1e9;
    //     if (i==0) return arr[0][j];
    //     if (dp[i][j] != INT_MIN) return dp[i][j];
    //     int up = arr[i][j] + solve(i-1,j,n,m,dp,arr);
    //     int left = arr[i][j] + solve(i-1,j-1,n,m,dp,arr);
    //     int right = arr[i][j] + solve(i-1,j+1,n,m,dp,arr);
    //     return dp[i][j] = min(up,min(left,right));
    // }

    //tabulation:
    int solve(int n,int m,vector<vector<int>> &dp,vector<vector<int>> &arr){
        for (int j=0;j<m;j++){
            dp[0][j] = arr[0][j];
        }
        for (int i=1;i<n;i++){
            for (int j=0;j<m;j++){
                int left = 1e9,right = 1e9;
                int up = arr[i][j] + dp[i-1][j];
                if (j>0) left = arr[i][j] + dp[i-1][j-1];
                if (j+1<m) right = arr[i][j] + dp[i-1][j+1];
                dp[i][j] = min(up,min(left,right));
            }
        }
        int mini = dp[n-1][0];
        for (int j=1;j<m;j++){
            mini = min(mini,dp[n-1][j]);
        }
        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        // for (int j=0;j<m;j++){
        //     mini = min(mini,solve(n-1,j,n,m,dp,matrix));
        // }
        return solve(n,m,dp,matrix);
    }
};