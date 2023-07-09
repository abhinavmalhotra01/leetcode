class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int out=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            int c=target-nums[i];
            // out-=nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(!(i!=j && j!=k && i!=k)){j++;k--;continue;}
                if(abs(nums[j]+nums[k]-c)<abs(out-target)){
                    out=nums[j]+nums[k]+nums[i];
                }
                if(nums[j]+nums[i]+nums[k]>target){k--;}
                else{j++;}
            }
            // out+=nums[i];
            while(i<nums.size()-1 && nums[i]==nums[i+1]){i++;}
        }
        return out;
    }
};