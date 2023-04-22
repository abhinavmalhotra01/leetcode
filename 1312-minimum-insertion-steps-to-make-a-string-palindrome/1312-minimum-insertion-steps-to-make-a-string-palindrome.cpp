class Solution {
    int dp[600][600];
    int n;
    string a,b;
    int rec(int i,int j){
        if(i>=n || j>=n){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        if(a[i]==b[j]){
            return dp[i][j]=1+rec(i+1,j+1);
        }
        return dp[i][j]=max(rec(i+1,j),rec(i,j+1));
    }
    int lcs(string& s , string& t){
        memset(dp,-1,sizeof(dp));
        n=s.size();
        a=s;
        b=t;
        return rec(0,0);
    }
public:
    int minInsertions(string s) {
        string t =s;
        reverse(t.begin(),t.end());
        int lc = lcs(s,t);
        return s.size()-lc;
    }
};