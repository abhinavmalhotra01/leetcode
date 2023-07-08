class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> v;
        for(int i=0;i<weights.size()-1;i++){
            v.push_back(weights[i]+weights[i+1]);
        }
        sort(v.rbegin(),v.rend());
        long long r=0,l=0;
        for(int i=0;i<k-1;i++){
            r+=(v[i]);
            l+=(v[v.size()-i-1]);
        }
        r+=weights[0]+weights[weights.size()-1];
        l+=weights[0]+weights[weights.size()-1];
        return r-l;
    }
};