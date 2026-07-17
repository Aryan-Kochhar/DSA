class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //if (grid.empty()) return -1;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                } else if (grid[i][j]==1) fresh++;
            }
        }
        int minutes = 0;
        while (!q.empty() && fresh>0){
            int size = q.size();
            while (size--){
                auto curr = q.front();q.pop();
                int row = curr.first;
                int col = curr.second;
                //up
                if (row>0 && grid[row-1][col]==1){
                    fresh--;
                    grid[row-1][col] = 2;
                    q.push({row-1,col});
                } 
                //down
                if (row<n-1 && grid[row+1][col]==1){
                    fresh--;
                    grid[row+1][col] = 2;
                    q.push({row+1,col});
                }
                //left
                if (col>0 && grid[row][col-1]==1){
                    fresh--;
                    grid[row][col-1] = 2;
                    q.push({row,col-1});
                }
                //right
                if (col<m-1 && grid[row][col+1]==1){
                    fresh--;
                    grid[row][col+1] = 2;
                    q.push({row,col+1});
                }
            }
            minutes++;
        }
        if (fresh>0) return -1;
        return minutes;
    }
};