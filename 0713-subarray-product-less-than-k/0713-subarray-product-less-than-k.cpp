class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int out=0;
        int i=0,j=0;
        int cur=1;
        while(j<nums.size()){
            if(cur*nums[j]<k){
                cur*=nums[j];
                out+=j-i+1;
                j++;
            }else{
                cur*=nums[j];
                // cout<<nums[j]<<endl;
                // int curr=(j-i)*(j-i+1);
                // curr/=2;
                // // cout<<curr<<endl;
                // out+=curr;
                // i++;j++;
                // cur=1;
                while(i<=j&&cur>=k){
                    cur/=nums[i];i++;
                }
                out+=j-i+1;
                j++;
            }
            
        }
        return out;
    }
};