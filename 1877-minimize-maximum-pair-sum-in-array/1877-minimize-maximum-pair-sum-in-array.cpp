class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int out=0;
        int i=0,j=nums.size()-1;
        while(i<=j){
            out=max(out,nums[i]+nums[j]);
            i++;j--;
        }
        return out;
    }
};