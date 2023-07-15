class Solution {
    int l_bound(int k,int l,vector<vector<int>>&v){
        int h = v.size()-1;
        int out=v.size();
        while(l<=h){
            int mid =(l+h)/2;
            if(v[mid][0]>=k){
                out=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return out;
    }
    int rec(int i,vector<int>& dp, vector<vector<int>>& v){
        if(i==v.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int cur=rec(i+1,dp,v);
        // vector<int> c = {v[i][1],INT_MAX,INT_MAX};
        // int j = lower_bound(v.begin(),v.end(),c)-v.begin();
        int j=l_bound(v[i][1],i,v);
        // if(j>v.size()){
        //     return dp[i]=cur;
        // }
        int cur2 = rec(j,dp,v)+v[i][2];
        return dp[i]=max(cur2,cur);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        int n=profit.size();
        for(int i=0;i<n;i++){
            vector<int> c = {startTime[i],endTime[i],profit[i]};
            v.push_back(c);
        }
        sort(v.begin(),v.end());
        vector<int> dp(n,-1);
        return rec(0,dp,v);
    }
};