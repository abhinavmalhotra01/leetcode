class Solution {
    void dfs(vector<int>& vis , int i, vector<int> adj[] ){
       vis[i]=1;
        for(auto e : adj[i]){
            // cout<<e<<endl;
            if(vis[e]){continue;}
            dfs(vis,e,adj);
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        vector<int> vis(strs.size(),0);
        vector<int> adj[strs.size()];
        for(int j=0;j<strs.size();j++){
            string e = strs[j];
            for(int h =0;h<strs.size();h++){
                string k = strs[h];
                int y=0;
                for(int i=0;i<k.size();i++){
                    if(e[i]!=k[i]){y++;}
                }
                if(y==0 || y==2){
                    // if(e==k){continue;}
                    // cout<<e<<" "<<k<<endl;
                    adj[j].push_back(h);
                }
            }
        }
        int out =0;
        for(int i=0;i<strs.size();i++){
            if(!vis[i]){
                // cout<<strs[i]<<endl;
                dfs(vis,i,adj);
                out++;
            }
        }
        return out;
    }
};