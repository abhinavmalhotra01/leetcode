class Solution {
    int dp[110][210];
    int mod=1e9+7;
    int rec(int i,int f,vector<int>&locations,int finish){
        if(f<0){return 0;}
        // if(i==finish){return 1;}
        // if(f==0){return 0;}
        if(dp[i][f]!=-1){
            return dp[i][f];
        }
        int curr=0;
        if(i==finish){curr=1;}
        for(int j=0;j<locations.size();j++){
            if(j!=i){
                // if(f-(abs(locations[j]-locations[i]))>=0){
                    curr=((curr%mod)+(rec(j,f-abs(locations[j]-locations[i]),locations,finish)%mod)%mod);
                    // cout<<i<<" "<<j<<" "<<f<<" "<<curr<<endl;
                // }
            }
        }
        return dp[i][f]=curr%mod;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        for(int i=0;i<110;i++){
            for(int j=0;j<210;j++){
                dp[i][j]=-1;
            }
        }
        return rec(start,fuel,locations,finish);
    }
};