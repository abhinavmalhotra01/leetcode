class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> ind(32,0);
        for(auto n:nums){
            int binaryNum[32];
            int i = 0;
            while (n > 0) {
                binaryNum[i] = n % 2;
                n = n / 2;
                i++;
            }
            for(int i=0;i<32;i++){
                if(binaryNum[i]==1){
                    ind[i]++;
                }
            }
        }
        int out=0;
        for(int i=0;i<32;i++){
            if(ind[i]){
                out+=(1<<i);
            }
        }
        return out;
    }
};