class Solution {
    int dp[1010][1010];
    int n,m;
    string s,t;
    int rec(int i,int j){
        if(i>=n && j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=n){
            return dp[i][j] = t[j] + rec(i, j+1);
        }else if(j>=m){
            return dp[i][j] = s[i] + rec(i+1, j);
        }
        // int c1=0,c2=0,c3=0;
        if(s[i]==t[j]){
            return dp[i][j]=rec(i+1,j+1);
        }
        int c2=rec(i+1,j)+s[i];
        int c3=rec(i,j+1)+t[j];
        return dp[i][j]=min({c2,c3});
    }
public:
    int minimumDeleteSum(string text1, string text2) {
        s=text1;
        t=text2;
        // cout<<s<<" "<<t;
        n=s.size();
        m=t.size();
        // cout<<n<<m;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};