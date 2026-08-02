class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (vis[i][j] || board[i][j] != 'O') return;
        vis[i][j] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++){
            dfs(i + dr[k], j + dc[k], board, vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){
            dfs(i, 0, board, vis);
            dfs(i, m-1, board, vis);
        }
        for (int j = 0; j < m; j++){
            dfs(0, j, board, vis);
            dfs(n-1, j, board, vis);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};