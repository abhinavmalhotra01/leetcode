class Solution {
    typedef long long ll;
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<ll,ll> m;
        ll out=0;
        for(auto &e:nums){
            ll cur = __gcd(k,e);
            for(auto &f:m){
                if((f.first*cur)%k ==0){
                    out+=f.second;
                }
            }
            m[cur]++;
        }
        return out;
    }
};