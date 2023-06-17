class Solution {
    int rec(int l,int r,int n,vector<vector<int>>& dp,vector<int>& slices){
        if(n==0 || l>r){
            return 0;
        }
        if(dp[l][n]!=-1){
            return dp[l][n];
        }
        int take = rec(l+2,r,n-1,dp,slices)+slices[l];
        int notTake = rec(l+1,r,n,dp,slices);
        return dp[l][n]=max(take,notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        vector<vector<int>> dp(slices.size()+1 ,vector<int>(slices.size()+1,-1));
        vector<vector<int>> dp2(slices.size()+1 ,vector<int>(slices.size()+1,-1));
        int a=rec(0,slices.size()-2,slices.size()/3,dp,slices);
        int b=rec(1,slices.size()-1,slices.size()/3,dp2,slices);
        return max(a,b);
    }
};