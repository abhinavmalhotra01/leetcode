class Solution {
    int dfs(int i,vector<int>adj[],vector<int>& vis){
        vis[i]=1;
        int curr=1;
        for(auto e:adj[i]){
            if(!vis[e]){
                curr+=dfs(e,adj,vis);
            }
        }
        return curr;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            int a = bombs[i][0];
            int b = bombs[i][1];
            int r = bombs[i][2];
            for(int j=0;j<n;j++){
                if(i==j){continue;}
                int c = bombs[j][0];
                int d = bombs[j][1];
                int f = bombs[j][2];
                double dist = sqrt(pow(c-a,2)+pow(d-b,2));
                if(dist<=r){
                    adj[i].push_back(j);
                }
            }
        }
        int out =1;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                for(int k=0;k<n;k++){vis[k]=0;}
                out=max(out,dfs(i,adj,vis));
            }
        }
        return out;
    }
};