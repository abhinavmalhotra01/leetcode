class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i=0,j=0;
        while(j<grid[0].size() && grid[i][j]>=0){j++;}
        int out=grid[0].size()-j;
        if(j==grid[0].size()){
            j--;
        }
        i++;
        // cout<<j<<endl;
        while(i<grid.size()){
            while(j>=0 && grid[i][j]<0){
                j--;
            }
            out+= grid[0].size()-j-1;
            i++;
        }
        return out;
    }
};