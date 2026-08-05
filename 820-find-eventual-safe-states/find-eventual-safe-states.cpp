class Solution {
public:

    bool dfsCheck(int node,const vector<vector<int>> &adj,vector<int> &vis, vector<int> &visPath,vector<int> &check){
        vis[node] = 1;
        check[node] = 0;
        visPath[node] = 1;
        for (auto it:adj[node]){
            if (!vis[it]){
                if (dfsCheck(it,adj,vis,visPath,check) == true) {
                    check[node] = 0;
                    return true;
                }
            }
            else if (visPath[it] == true) return true;
        }
        visPath[node] = 0;
        check[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>&adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        vector<int> visPath(n,0);
        // vector<vector<int>> adj(n);
        vector<int> safeNodes;
        vector<int> check(n,0);

        // for (int i=0;i<n;i++){
        //     for (auto it:adj[i]){
        //         adj[i].push_back(it);
        //     }
        // }
        for (int i=0;i<n;i++){
            if (!vis[i]){
                dfsCheck(i,adj,vis,visPath,check);
            }
        }

        for (int i=0;i<n;i++){
            if (check[i]==1) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};