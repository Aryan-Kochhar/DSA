class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>> &dp,vector<vector<int>> &arr){
        if (j<0 || j>=m) return 1e9;
        if (i==0) return arr[0][j];
        if (dp[i][j] != INT_MIN) return dp[i][j];
        int up = arr[i][j] + solve(i-1,j,n,m,dp,arr);
        int left = arr[i][j] + solve(i-1,j-1,n,m,dp,arr);
        int right = arr[i][j] + solve(i-1,j+1,n,m,dp,arr);
        return dp[i][j] = min(up,min(left,right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MIN));
        int mini = 1e9;
        for (int j=0;j<m;j++){
            mini = min(mini,solve(n-1,j,n,m,dp,matrix));
        }
        return mini;
    }
};