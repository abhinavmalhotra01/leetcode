class Solution {
    int MOD = 1e9+7;
    int rec(int n,int cur,vector<vector<int>>& dp,int x){
        if(n<0){return 0;}
        if(n==0){return 1;}
        if(pow(cur,x)>n){return 0;}
        if(dp[n][cur]!=-1){return dp[n][cur];}
        int curN = pow(cur,x);
        int a = rec(n-curN,cur+1,dp,x);
        int b = rec(n,cur+1,dp,x);
        return dp[n][cur]= ((a%MOD)+(b%MOD))%MOD;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(310,vector<int>(310,-1));
        return rec(n,1,dp,x);
    }
};