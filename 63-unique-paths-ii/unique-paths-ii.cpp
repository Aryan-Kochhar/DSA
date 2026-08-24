class Solution {
public:
    int helper(int n,int m,vector<vector<int>> &dp,vector<vector<int>> &grid){
        if (n<0 || m<0) return 0;
        if (grid[n][m] == 1) return 0;
        if (n==0 && m==0) return 1;
        if (dp[n][m] != -1) return dp[n][m];
        int up = helper(n-1,m,dp,grid);
        int left = helper(n,m-1,dp,grid);
        return dp[n][m] = up+left;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        //if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // dp[0][0] = 1;
        // for (int i=0;i<n;i++){
        //     for (int j=0;j<m;j++){
        //         int up = 0,left = 0;
        //         if (i==0 && j==0 || obstacleGrid[i][j]==1)  continue;
        //         if (i>0) up = dp[i-1][j];
        //         if (j>0) left = dp[i][j-1];
        //         dp[i][j] = up+left;
        //     }
        // }
        //return dp[n-1][m-1];
        return helper(n-1,m-1,dp,obstacleGrid);
    }
};