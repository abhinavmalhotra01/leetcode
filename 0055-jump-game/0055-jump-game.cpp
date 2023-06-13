class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr=0;
        for(int i=0;i<nums.size();i++){
            if(i>curr){return false;}
            curr=max(curr,nums[i]+i);
        }
        return true;
    }
};