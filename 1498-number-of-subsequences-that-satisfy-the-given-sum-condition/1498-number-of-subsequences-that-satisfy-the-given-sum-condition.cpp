class Solution {
    long long int mod = 1e9+7;
    // long long int pow2(int i,int j){
    //     if(j==0){return 1;}
    //     return ((i%mod)*(pow2(i,j-1)%mod))%mod;
    // }
    long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%mod) * (a%mod))%mod;
        a = ((a%mod) * (a%mod))%mod;
        b >>= 1;
    }
    return res;
}
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        long long int out =0;
        while(i<=j){
            if(nums[j]+nums[i]<=target){
                out = ((out)%mod + (binpow(2,(j-i))%mod))%mod;
                i++;
            }else{
                j--;
            }
        }
        return out;
    }
};