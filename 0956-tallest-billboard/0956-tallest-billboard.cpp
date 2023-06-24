class Solution {
    int dp[30][10010];
    int rec(int i, int l,vector<int>& rods){
        if(i>=rods.size()){
            if(l==0){return 0;}
            else{
                return INT_MIN;
            }
        }
        if(dp[i][l+5000]!=-1){
            return dp[i][l+5000];
        }
        int curr=rods[i]+rec(i+1,l+rods[i],rods);
        curr=max(curr,rec(i+1,l-rods[i],rods));
        curr=max(curr,rec(i+1,l,rods));
        return dp[i][l+5000]=curr;
    }
public:
    int tallestBillboard(vector<int>& rods) {
        for(int i=0;i<30;i++){
            for(int j=0;j<10010;j++){
                dp[i][j]=-1;
            }
        }
        return rec(0,0,rods);
    }
};