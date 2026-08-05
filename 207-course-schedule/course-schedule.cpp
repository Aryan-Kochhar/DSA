class Solution {
public:
    bool dfsCheck(int src,const vector<vector<int>> &adj,vector<int> &vis,vector<int> &pathVis){
        vis[src] = 1;
        pathVis[src] = 1;
        for (auto it:adj[src]){
            if (!vis[it]){
                if (dfsCheck(it,adj,vis,pathVis)==true) return true;
            }
            else if (pathVis[it]) return true;
        }
        pathVis[src] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for (int i=0;i<numCourses;i++){
            if (!vis[i]){
                if (dfsCheck(i,adj,vis,pathVis)) return false;
            }
        }    
        return true;
    }
};