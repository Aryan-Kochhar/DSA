class Solution {
public:
    bool detectCycle(int node,const vector<vector<int>> &adj,vector<int> &vis,vector<int> &pathVis,vector<int> &ans){
        vis[node] = 1;
        pathVis[node] =1;
        for (auto it:adj[node]){
            if (!vis[it]){
                if (detectCycle(it,adj,vis,pathVis,ans)==true) return true;
            }
            else if (pathVis[it]==1) return true;
        }
        pathVis[node] = 0;
        ans.push_back(node);
        return false; 
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        for (auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for (int i=0;i<numCourses;i++){
            if (!vis[i]){
                if (detectCycle(i,adj,vis,pathVis,ans)) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};