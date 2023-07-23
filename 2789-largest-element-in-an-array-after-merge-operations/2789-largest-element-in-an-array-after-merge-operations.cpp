class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int f=0;
        vector<long long> v;
        for(auto e:nums){v.push_back(e);}
        for(int i=v.size()-1;i>0;i--){
            if(v[i]>=v[i-1]){
                v[i-1]+=v[i];
                f=i-1;
            }
        }
        return max(v[f],*max_element(begin(v),end(v)));
    }
};