class Solution {
    vector<int> v;
    int a;
    int dp[110][110];
    int rec(int i,int j){
        if(i>j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int out=INT_MAX;
        for(int k=i;k<=j;k++){
            int curr = v[j+1]-v[i-1]+rec(i,k-1)+rec(k+1,j);
            out=min(out,curr);
        }
        return dp[i][j]=out;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        a=n;
       v.push_back(0);
       for(int i=0;i<cuts.size();i++){
           v.push_back(cuts[i]);
       }
       v.push_back(n);
       memset(dp,-1,sizeof(dp));
        return rec(1,cuts.size());
    }
};