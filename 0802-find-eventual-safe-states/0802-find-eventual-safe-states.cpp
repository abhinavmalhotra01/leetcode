class Solution {
    bool dfs(int i,vector<int>& vis,vector<int>& pathvis,vector<int>adj[],vector<int>& out){
        vis[i]=1;
        pathvis[i]=1;
        out[i]=0;
        for(auto e:adj[i]){
            if(!vis[e]){
                if(dfs(e,vis,pathvis,adj,out)){
                    return true;
                }
            }else if(pathvis[e]){
                return true;
            }
        }
        out[i]=1;
        pathvis[i]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        vector<int> pathvis(graph.size(),0);
        vector<int> adj[graph.size()];
        for(int i=0;i<graph.size();i++){
            vector<int> curr;
            for(int j=0;j<graph[i].size();j++){
                curr.push_back(graph[i][j]);
            }
            adj[i]=curr;
        }
        vector<int> out(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,adj,out);
            }
        }
        vector<int> out2;
        for(int i=0;i<graph.size();i++){
            if(out[i]){
                out2.push_back(i);
            }
        }
        return out2;
    }
};