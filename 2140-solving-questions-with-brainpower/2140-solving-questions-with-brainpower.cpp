class Solution {
    long long dp[100010];
    long long rec(int i,vector<vector<int>>& questions){
        if(i>=questions.size()){
            return 0;
        }
        if(dp[i]!=-1){return dp[i];}
        long long c1 = rec(i+questions[i][1]+1,questions)+questions[i][0];
        long long c2 = rec(i+1,questions);
        return dp[i]=max(c1,c2);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return rec(0,questions);
    }
};