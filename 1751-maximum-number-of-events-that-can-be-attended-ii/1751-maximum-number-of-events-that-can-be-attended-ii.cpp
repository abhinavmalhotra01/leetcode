class Solution {
    int rec(int i,int k,vector<vector<int>>& events,vector<vector<int>>& dp){
        if(i>=events.size() || k<=0){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        vector<int> v={events[i][1],INT_MAX,INT_MAX};
        int j= upper_bound(events.begin(),events.end(),v)-events.begin();
        int cur=rec(i+1,k,events,dp);
        cur=max(cur,rec(j,k-1,events,dp)+events[i][2]);
        return dp[i][k]=cur;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
        return rec(0,k,events,dp);
    }
};