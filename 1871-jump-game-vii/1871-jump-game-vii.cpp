class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]=='1'){return 0;}
        int pre=0;
        vector<int> dp(s.size(),0);
        dp[0]=1;
        for(int i=1;i<s.size();i++){
            if(i>=minJump){
                pre+=dp[i-minJump];
            }
            if(i>maxJump){
                pre-=dp[i-maxJump-1];
            }
            dp[i] = pre>0 && s[i]=='0';
        }
        return dp[s.size()-1];
    }
};