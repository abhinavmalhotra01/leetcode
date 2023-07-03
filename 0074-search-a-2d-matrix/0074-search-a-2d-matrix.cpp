class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int r = *lower_bound(matrix[0].begin(),matrix[matrix.size()-1].end(),target);
        // cout<<r;return 1;
        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=m*n-1;
        while(l<=r){
            int mid= l + (r-l)/2;
            if(matrix[mid/n][mid%n]==target) return 1;
            else if(matrix[mid/n][mid%n]>target) r=mid-1;
            else l=mid+1;
        }
        return 0;
    }
};