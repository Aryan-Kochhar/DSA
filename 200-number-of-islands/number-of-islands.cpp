class Solution {
public:
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vis[row][col] = 1;
        q.push({row,col});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while (!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i=0;i<4;i++){
                int nrow = r+dr[i];
                int ncol = c+dc[i];
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};