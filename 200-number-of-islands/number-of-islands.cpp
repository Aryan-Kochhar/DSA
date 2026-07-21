class Solution {
public:
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis){
        vis[row][col] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i=0;i<4;i++){
                int r = row+dr[i];
                int c = col+dc[i];
                if (r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]=='1'){
                    vis[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for (int row=0;row<n;row++){
            for (int col=0;col<m;col++){
                if (!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,grid,vis);
                }
            }
        }
        return cnt;
    }
};