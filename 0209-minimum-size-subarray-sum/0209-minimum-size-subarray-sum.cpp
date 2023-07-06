class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int out=INT_MAX;
        int i=0,j=0;
        int curr=0;
        while(j<nums.size()){
            if(curr+nums[j]<target){
                // cout<<curr<<endl;
                curr+=nums[j];
            }else{
                curr+=nums[j];
               while(curr>=target){
                   // cout<<i<<endl;
                   out=min(out,j-i+1);
                   curr-=nums[i];
                   i++;
               }
            }
            j++;
        }
        if(out> nums.size()){return 0;}
        return out;
    }
};