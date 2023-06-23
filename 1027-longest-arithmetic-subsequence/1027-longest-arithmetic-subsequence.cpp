class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int,int>> dp(nums.size());
        int out =0;
        if(nums.size()<=2){return nums.size();}
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int curr = nums[i]-nums[j];
                if(dp[j].count(curr)){
                    dp[i][curr]=dp[j][curr]+1;
                }else{
                    dp[i][curr]=2;
                }
                out=max(out,dp[i][curr]);
            }
        }
        return out;
    }
};