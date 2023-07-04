class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out=0;
        for(int i=31;i>=0;i--){
            int curr=0;
            for(auto e:nums){
                if((e>>i)&1){
                    curr++;
                }
            }
            if(curr%3){
                out+=(1<<i);
            }
        }
        return out;
    }
};