class Solution {
    int dp[100010][3];
    int n,k;
    vector<int> arr;
    int rec(int i,int buy){
        if(i>=n){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy){
            return dp[i][buy]=max(-arr[i]+rec(i+1,0),rec(i+1,1));
        }else{
            return dp[i][buy]=max(arr[i]+rec(i+1,1)-k,rec(i+1,0));
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();k=fee;
        for(int i=0;i<n;i++){
            arr.push_back(prices[i]);
        }
        memset(dp,-1,sizeof(dp));
        return rec(0,1);
    }
};