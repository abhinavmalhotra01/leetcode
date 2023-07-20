class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int out=0;
        vector<int> dr={1,-1,0,0};
        vector<int> dc={0,0,-1,1};
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){continue;}
                if(!vis[i][j]){
                    // cout<<i<<" "<<j<<" ";
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=1;
                    int cur=1;
                    while(q.size()){
                        auto e = q.front();
                        // if(!vis[e.first][e.second]){cur++;}
                        q.pop();
                        // cout<<e.first<<" "<<e.second<<endl;
                        // vis[e.first][e.second]=1;
                        for(int k=0;k<4;k++){
                            int nr = e.first+dr[k];
                            int nc = e.second+dc[k];
                            // if(i==1 && j==7){
                            //     cout<<nr<<" "<<nc<<" b ";
                            // }
                            if(nc>=0 && nc<grid[0].size() && nr>=0 && nr<grid.size() && grid[nr][nc]==1 && !vis[nr][nc]){
                                q.push({nr,nc});
                                vis[nr][nc]=1;
                                cur++;
                            }
                        }
                    }
                    // cout<<endl;
                    out=max(out,cur);
                }
            }
        }
        return out;
    }
};