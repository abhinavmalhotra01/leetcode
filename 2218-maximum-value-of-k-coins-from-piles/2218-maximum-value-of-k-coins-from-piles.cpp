class Solution {
    
    int dp[1010][2010];
    int rec(vector<vector<int>>& piles,int i,int j){
        if(i==piles.size()){return 0;}
        if(j<=0){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int no = rec(piles,i+1,j);
        int ta = 0;
        int s =0;
        for(int c=0;c<min((int)(j),(int)(piles[i].size()));c++){
            s+=piles[i][c];
            int cur=0;
            if(j-(c+1)>=0){
                cur=s+rec(piles,i+1,j-(c+1));
            }
            ta = max(ta,cur);
        }
        return dp[i][j]=max(no,ta);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(piles,0,k);
    }
};