class Solution {
    bool dfs(int i,vector<int> adj[],vector<int>& vis, int curr){
        vis[i]=curr;
        for(auto e:adj[i]){
            if(vis[e]!=-1){if(vis[e]==curr){return false;}}
            else{
                if(!dfs(e,adj,vis,!curr)){
                    return false;
                };
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int out =0;
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto e:graph[i]){
                adj[i].push_back(e);
            }
        }
        int curr = 0;
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                bool c = dfs(i,adj,vis,!curr);
                if(!c){
                    return false;
                }
            }
        }
        return true;
    }
};