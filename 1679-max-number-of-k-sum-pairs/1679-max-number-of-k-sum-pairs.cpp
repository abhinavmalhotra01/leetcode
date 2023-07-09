class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int out=0;
        int i=0,j=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(i<j){
            if(nums[i]+nums[j]==k){out++;i++;j--;}
            else if(nums[i]+nums[j]>k){j--;}
            else{i++;}
        }
        return out;
    }
};