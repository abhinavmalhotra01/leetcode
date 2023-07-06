class Solution {
    // int dp[110][110];
    // int m,n;
    // int rec(int i,int j){
    //     if(i==m-1 && j==n-1){return 1;}
    //     if(dp[i][j]!=-1){return dp[i][j];}
    //     dp[i][j]=0;
    //     if(i+1<m){
    //         dp[i][j]+=rec(i+1,j);
    //     }if(j+1<n){
    //         dp[i][j]+=rec(i,j+1);
    //     }
    //     return dp[i][j];
    // }
public:
    int uniquePaths(int m, int n) {
        // m=x;n=y;
        // for(auto &e:dp){
        //     for(auto &f:e){
        //         f=-1;
        //     }
        // }
        // return rec(0,0);
        int N = n + m - 2;
        int r = m - 1; 
        double res = 1;
        for (int i = 1; i <= r; i++){
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};