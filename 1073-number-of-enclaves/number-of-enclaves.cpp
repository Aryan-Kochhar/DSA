class Solution{
public:
    void dfs(int i,int j, vector<vector<int>> &vis, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        if (i<0 || j<0 || i>=n || j>=m) return;
        if (vis[i][j] || grid[i][j]!=1) return;
        vis[i][j] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        for (int k = 0;k<4;k++){
            dfs(i+dr[k],j+dc[k],vis,grid);
        }
    }
    int numEnclaves(vector<vector<int>> &grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i=0;i<n;i++){
            dfs(i,0,vis,grid);
            dfs(i,m-1,vis,grid);
        }
        for (int j=0;j<m;j++){
            dfs(0,j,vis,grid);
            dfs(n-1,j,vis,grid);
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!vis[i][j] && grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};