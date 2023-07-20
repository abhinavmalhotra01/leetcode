class Solution {
    int time=1;
    void dfs(int i,int par,vector<int>adj[],vector<int>& vis , vector<vector<int>>& out,vector<int>& tin,vector<int>& low){
        vis[i]=1;
        tin[i]=time;
        low[i]=time;
        time++;
        for(auto e:adj[i]){
            if(e==par){continue;}
            if(!vis[e]){
                dfs(e,i,adj,vis,out,tin,low);
                low[i]=min(low[i],low[e]);
                if(low[e]>tin[i]){
                    // cout<<e<<" "<<i<<endl;
                    out.push_back({i,e});
                }
            }else{
                low[i]=min(low[i],tin[e]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> tin(n,0);
        vector<int> low(n,0);
        vector<int> adj[n];
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<vector<int>> out;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,out,tin,low);
            }
        }
        return out;
    }
};