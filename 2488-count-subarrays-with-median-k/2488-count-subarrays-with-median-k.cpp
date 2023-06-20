class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int ki = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k){
                ki=i;break;
            }
        }
        map<int,int> m;
        int more=0,less=0;
        for(int i=ki;i<nums.size();i++){
            if(nums[i]>k){
                // cout<<nums[i]<<" "<<nums[ki]<<" ";
                more++;}
            else if(nums[i]!=k){less++;}
            int curr=more-less;
            // cout<<nums[i]<<" "<<curr<<endl;
            m[curr]++;
        }
        more=0,less=0;
        int out=0;
        for(int i=ki;i>=0;i--){
            if(nums[i]>k){more++;}
            else if(nums[i]!=k){less++;}
            int curr = more-less;
            // cout<<curr<<endl;
            if(m.count(-curr)>0){out+=m[-curr];}
            if(m.count(-curr+1)>0){out+=m[-curr+1];}
        }
        return out;
    }
};