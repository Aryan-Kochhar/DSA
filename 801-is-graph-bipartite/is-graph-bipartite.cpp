class Solution {
public:
    //bfs
    bool check(const int start,const int V,vector<int> &colour,const vector<vector<int>> &graph){
        queue<int> q;
        q.push(start);
        colour[start] = 0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (auto it : graph[node]){
                if (colour[it]==-1){
                    colour[it] = !colour[node];
                    q.push(it);
                } else if (colour[it]==colour[node]) return false;
            }
        }
        return true;
    }

    //dfs
    bool dfs(int node,int col,vector<int> &colour,const vector<vector<int>> &graph){
        colour[node] = col;
        for (auto it:graph[node]){
            if (colour[it]==-1){
                if (dfs(it,!colour[node],colour,graph) == false) return false;
            }
            else if (colour[it]==colour[node]) return false;
        }
        return true;
    }

    bool isBipartite(const vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> colour(V,-1);
        for (int i=0;i<V;i++){
            if (colour[i]==-1){
                //bfs
                //if (check(i,V,colour,graph)==false) return false;

                //dfs
                if (dfs(i,0,colour,graph)==false) return false;
            }
        }
        return true;
    }
};