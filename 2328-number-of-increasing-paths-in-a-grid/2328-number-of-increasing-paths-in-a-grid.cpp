class Solution {
    int mod =1e9+7;
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i>=grid.size() || j>=grid[0].size() || j<0 || i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int curr =0;
        if(i+1<grid.size() && grid[i+1][j]>grid[i][j]){
            curr=((curr)%mod+(dfs(i+1,j,grid,dp)%mod))%mod;
        }
        if(i-1>=0 && grid[i-1][j]>grid[i][j]){
            curr=((curr)%mod+(dfs(i-1,j,grid,dp)%mod))%mod;
        }
        if(j+1<grid[0].size() && grid[i][j+1]>grid[i][j]){
            curr=((curr)%mod+(dfs(i,j+1,grid,dp)%mod))%mod;
        }
        if(j-1>=0 && grid[i][j-1]>grid[i][j]){
            curr=((curr)%mod+(dfs(i,j-1,grid,dp)%mod))%mod;
        }
        curr++;
        return dp[i][j]=curr;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+10,vector<int>(grid[0].size()+10,-1));
        int out=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                out=((out%mod)+(dfs(i,j,grid,dp)%mod))%mod;
            }
        }
        return out;
    }
};