class Solution {
    vector<int> dir={-1,1,0,0};
    vector<int> dic = {0,0,-1,1};
    void dfs(int i,int j,set<pair<int,int>>& s,vector<vector<int>>& v,vector<vector<int>>& vis){
        if(vis[i][j]){
            return;
        }
        vis[i][j]=1;
        s.insert({i,j});
        for(int k=0;k<4;k++){
            int r = i+dir[k];
            int c = j+dic[k];
            if(r>=0 && c>=0 && r<v.size() && c<v[0].size() && v[r][c] && !vis[r][c]){
                dfs(r,c,s,v,vis);
            }
        }
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> vis(land.size(),vector<int>(land[0].size(),0));
        vector<vector<int>> out;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(!vis[i][j] && land[i][j]==1){
                    set<pair<int,int>> s;
                    dfs(i,j,s,land,vis);
                    // vector<int> cur;
                    auto f =s.end();
                    f--;
                    auto e=s.begin();
                    auto ed = *e;
                    auto ef=*f;
                    out.push_back({ed.first,ed.second,ef.first,ef.second});
                }
            }
        }
        return out;
    }
};