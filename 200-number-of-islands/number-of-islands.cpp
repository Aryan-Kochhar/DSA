class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        vis[i][j] = 1;
        for (int k=0;k<4;k++){
            // dfs(i+dr[k],j+dc[k],vis,grid);
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1'){
                dfs(nr,nc,vis,grid);
            }
        }
        //if (i<n && j<m && i>=0 && j>=0 && grid[i][j]=='1' && !vis[i][j]){
    }

    void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        vis[i][j] = 1;
        q.push({i,j});
        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int size = q.size();
            for (int k=0;k<4;k++){
                int nr = row+dr[k];
                int nc = col+dc[k];
                if (nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        // for (int i=0;i<n;i++){
        //     for (int j=0;j<m;j++){
        //         if (!vis[i][j] && grid[i][j]=='1'){
        //             count++;
        //             dfs(i,j,vis,grid);
        //         }
        //     }
        // }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};