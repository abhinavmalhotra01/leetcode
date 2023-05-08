class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int out =0;
        int i=0,j=0;
        while(i<mat.size() && j<mat[0].size()){
            out+=mat[i][j];
            i++;j++;
        }
        i=0,j=mat[0].size()-1;
        while(i<mat.size() && j>=0){
            if(mat.size()%2){
                if(i==mat.size()/2 && j==mat[0].size()/2){
                    i++;j--;
                    continue;
                }
            }
            out+=mat[i][j];
            i++;j--;
        }
        return out;
    }
};