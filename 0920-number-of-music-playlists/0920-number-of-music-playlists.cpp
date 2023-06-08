class Solution {
    int mod = 1e9+7;
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(110,vector<long long>(110,0));
        dp[0][0]=1;
        for(int i=1;i<=goal;i++){
            for(int j=1;j<=i && j<=n;j++){
                dp[i][j]=(dp[i-1][j-1]*((n-j+1)%mod))%mod;
                if(j<k){continue;}
                dp[i][j]=((dp[i][j]%mod)+(dp[i-1][j]*(j-k))%mod)%mod;
            }
        }
        return dp[goal][n];
    }
};