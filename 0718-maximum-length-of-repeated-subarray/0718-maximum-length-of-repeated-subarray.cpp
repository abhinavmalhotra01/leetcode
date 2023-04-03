class Solution {
    int out=0;
    int n,m;
    int dp[1010][1010];
    int rec(int i, int j,vector<int>& nums1, vector<int>& nums2){
        if(dp[i][j]!=-1){return dp[i][j];}
        if(i==n || j==m){return dp[i][j]=0;}
        int canve=0;
        if(nums1[i]==nums2[j]){
            canve= rec(i+1,j+1,nums1,nums2)+1;
            out=max(out,canve);
        }
        rec(i,j+1,nums1,nums2);
        rec(i+1,j,nums1,nums2);
        
        return dp[i][j]=canve;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        n= nums1.size();
        m=nums2.size();
        rec(0,0,nums1,nums2);
        return out;
    }
};