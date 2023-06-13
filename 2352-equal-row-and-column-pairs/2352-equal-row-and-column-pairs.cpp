class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> m;
        for(int  i=0;i<grid.size();i++){
            vector<int> curr;
            for(int j=0;j<grid.size();j++){
                curr.push_back(grid[i][j]);
            }
            m[curr]++;
        }
        int out =0;
        for(int i=0;i<grid.size();i++){
            vector<int> curr;
            for(int j=0;j<grid.size();j++){
                curr.push_back(grid[j][i]);
            }
            if(m.count(curr)>0){
                out+=m[curr];
            }
        }
        return out;
    }
};