class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int curR=0,curC=matrix[0].size()-1;
        while(curR<matrix.size() && curC>=0){
            if(target==matrix[curR][curC]){
                // cout<<curR<<" "<<curC;
                return 1;
            }else if(target>matrix[curR][curC]){
                curR++;
            }else{
                curC--;
            }
        }
        return 0;
    }
};