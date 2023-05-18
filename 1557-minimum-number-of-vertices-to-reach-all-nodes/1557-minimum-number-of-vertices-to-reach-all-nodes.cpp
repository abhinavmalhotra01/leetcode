class Solution {
    void dfs(vector<int> adj[] , int n , vector<int>& vis , int i){
        vis[i]=1;
        for(auto e:adj[i]){
            if(!vis[e]){
                dfs(adj,n,vis,e);
            }
        }
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<int> out;
        map<int,int> m;
        for(auto e:edges){
            m[e[1]]++;
        }
        for(int i=0;i<n;i++){
            if(m.count(i)==0){
                out.push_back(i);
            }
        }
        return out;
    }
};