class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> m;
        int c=0;
        for(auto e:nums){
            m[e%space]++;
            c=max(c,m[e%space]);
        }
        int out=INT_MAX;
        for(auto e:nums){
            if(m[e%space]==c){
                out=min(out,e);
            }
        }
        return out;
    }
};