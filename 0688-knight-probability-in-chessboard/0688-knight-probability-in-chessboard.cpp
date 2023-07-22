class Solution {
    vector<int> dir={1,2,2,1,-1,-2,-2,-1};
    vector<int> dic={-2,-1,1,2,2,1,-1,-2};
    unordered_map<string,double> dp;
    double rec(int i,int j,int k,int n){
        if(i>=n || j>=n || i<0 || j<0){
            return 0.0;
        }
        if(k==0){return 1.0;}
        // if(dp[i][j]!=-1){
        //     return dp[i][j];
        // }
        string cur = to_string(i)+"#"+to_string(j)+"#"+to_string(k);
        if(dp.count(cur)){
            return dp[cur];
        }
        double a =0;
        for(int c=0;c<8;c++){
            int cur=i+dir[c];
            int cuc=j+dic[c];
            a+= rec(cur,cuc,k-1,n);
        }
        // cout<<a<<" ";
        a/=8.0;
        // cout<<a<<endl;
        dp.insert({cur,a});
        return dp[cur];
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        // vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        return rec(row,column,k,n);
    }
};