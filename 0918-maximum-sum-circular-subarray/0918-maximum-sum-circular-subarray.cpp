class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int out=INT_MIN,cur=0,out2=INT_MAX,cur2=0;
        int t=0;
        for(int i=0;i<nums.size();i++){
            t+=nums[i];
            cur+=nums[i];
            out=max(out,cur);
            if(cur<0){cur=0;}
            cur2+=nums[i];
            out2=min(out2,cur2);
            if(cur2>0){cur2=0;}
        }
        if(t==out2){
            return out;
        }
        return max(out,t-out2);
    }
};