class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int out=0;
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[0].size()-2;j++){
                int curr=grid[i][j];
                if(j+1<grid[0].size()){
                    curr+=grid[i][j+1];
                }else{continue;}
                if(j+2<grid[0].size()){
                    curr+=grid[i][j+2];
                }else{continue;}
                if(i+1<grid.size()){
                    curr+=grid[i+1][j+1];
                }else{continue;}
                if(i+2<grid.size()){
                    curr+=grid[i+2][j];
                    curr+=grid[i+2][j+1];
                    curr+=grid[i+2][j+2];
                }else{
                    continue;
                }
                out=max(out,curr);
            }
        }
        return out;
    }
};