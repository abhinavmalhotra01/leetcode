class Solution {
    int mod = 1e9+7;
    int dp[100010];
    int rec(int l , int h,int z , int o , int i){
        if(i>h){return 0;}
        if(dp[i]!=-1){return dp[i];}
        int curr=0;
        if(i>=l && i<=h){curr=1;}
        curr+=rec(l,h,z,o,i+z);
        curr=((curr)%mod + (rec(l,h,z,o,i+o)%mod))%mod;
        return dp[i]=curr%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return rec(low,high,zero,one,0);
    }
};