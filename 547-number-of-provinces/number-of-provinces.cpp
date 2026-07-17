class Solution {
public:
    int cnt = 0;
    void dfs(int start,vector<vector<int>> &adj,vector<bool> &vis){
        vis[start] = true;
        for (auto it:adj[start]){
            if (!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for (int i=0;i<n;i++){
            if (!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};