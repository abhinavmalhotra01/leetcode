class Solution {
    void dfs(int i,vector<int>& vis , vector<int> adj[]){
        vis[i]=1;
        for(auto e:adj[i]){
            if(!vis[e]){
                dfs(e,vis,adj);
            }
        }
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> adj[arr.size()];
        map<int,int> m;
        for(int  i=0;i<arr.size();i++){
            if(arr[i]==0){m[i]++;}
            if(i+arr[i]<arr.size()){
                adj[i].push_back(arr[i]+i);
            }
            if(i-arr[i]>=0){
                adj[i].push_back(i-arr[i]);
            }
        }
        vector<int> vis(arr.size(),0);
        dfs(start,vis,adj);
        for(auto e:m){
            if(vis[e.first]){
                return 1;
            }
        }
        return 0;
    }
};