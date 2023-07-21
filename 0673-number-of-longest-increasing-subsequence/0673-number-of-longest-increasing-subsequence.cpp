class Solution {
    int dp[3000],cnt[3000];
    // int ans=0;
    // int cnt=0;
    int rec(int i , vector<int>& nums){
        int ans =1,cn=1;
        if(dp[i]!=-1){return dp[i];}
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                if(rec(j,nums)+1 > ans){
                    // cnt[j]++;
                    ans=rec(j,nums)+1;
                    cn=cnt[j];
                    // cout<<""
                }
                else if(rec(j,nums)+1 == ans){
                    // cout<<" j"
                    cn+=cnt[j];
                }
            }
        }
        cnt[i]=cn;
        return dp[i]=ans;
    }
    // int rec_(int i , vector<int>& nums){
    //     int cur =1;
    //     if(dp[i]!=-1){return dp[i];}
    //     for(int j=0;j<=i;j++){
    //         if(nums[i]>nums[j]){
    //             if(rec_(j,nums)+1 > cur){
                    // // cout<<rec_(j,nums)+1;
    //                 // if(rec_(j,nums)+1 == ans){
    //                 //     // cout<<endl<<nums[i]<<" "<<nums[j]<<endl;
    //                 //     cnt++;
    //                 //     // cout<<cnt[i]<<endl;
    //                 // }
    //                 // cur=rec_(j,nums)+1;

    //             }
    //         }
    //     }
    //     return dp[i]=cur;
    // }
public:
    int findNumberOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,rec(i,nums));
        }
        // for(int i=0;i<2002;i++){cnt[i]=1;}
        // memset(dp,-1,sizeof(dp));
        int out=0;
        for(int i=0;i<nums.size();i++){
            // cout<<dp[i]<<" "<<ans<<endl;
            if(dp[i]==ans){
                // cout<<i<<" "<<cnt[i]<<endl;
                out+=cnt[i];
            }
        }
        // if(ans==1){
        //     return nums.size();
        // }
        // cout<<ans<<endl;
        // 
        // for(int i=0;i<nums.size();i++){
        //     out=max(out,cnt[i]);
        // }
        return out;
    }
};