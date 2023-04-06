class Solution {
    void dfs (vector<vector<int>>& grid, int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]){return;}
        grid[i][j]=1;
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        for(int k=0;k<4;k++){
            int cur = i+dr[k];
            int cuc = j+dc[k];
            dfs(grid,cur,cuc);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        // vector<vector<int>> vis( grid.size() , vector<int> (grid[0].size(), 0));
        for(int i=0;i<grid.size();i++){
            dfs(grid,i,0);
            dfs(grid,i,grid[0].size()-1);    
        }
        for(int i=0;i<grid[0].size();i++){
            dfs(grid,0,i);
            dfs(grid,grid.size()-1,i);
        }
        int out =0;
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if( !grid[i][j]){
                    dfs(grid,i,j);
                    // cout<<i<<" "<<j<<endl;
                    out++;
                }
            }
        }
        return out;
    }
};