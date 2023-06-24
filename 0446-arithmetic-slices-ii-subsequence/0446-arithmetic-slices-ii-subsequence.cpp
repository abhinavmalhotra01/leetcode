class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        vector<unordered_map<long long int,long long int>> dp(nums.size());
        int out =0;
        // if(nums.size()<=2){return nums.size();}
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long long int curr = 1ll*nums[i]-1ll*nums[j];
                // int curr2= nums[j]-(nums[i]-nums[j]);
                int d=0;
                if(dp[j].count(curr)){
                    d=dp[j][curr];
                }
                dp[i][curr]+=d+1;
                out+=d;
            }
        }
        return out;
    }
};
