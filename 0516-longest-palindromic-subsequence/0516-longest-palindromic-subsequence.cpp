class Solution {
    int dp[1010][1010];
    int n,m;
    string s,t;
    int rec(int i,int j){
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int c1=0,c2=0,c3=0;
        if(s[i]==t[j]){
            c1=rec(i+1,j+1)+1;
        }
        else{
            c2=rec(i+1,j);
            c3=rec(i,j+1);
        }
        return dp[i][j]=max({c1,c2,c3});
    }
    int longestCommonSubsequence(string text1, string text2) {
        s=text1;
        t=text2;
        // cout<<s<<" "<<t;
        n=s.size();
        m=t.size();
        // cout<<n<<m;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
};