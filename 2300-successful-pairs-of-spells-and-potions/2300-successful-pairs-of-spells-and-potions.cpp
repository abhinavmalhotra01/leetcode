class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> out;
        for(auto e : spells){
            long long req = success/e;
            if(success %e){req++;}
            auto it = lower_bound(potions.begin(),potions.end(),req);
            out.push_back(potions.end()-it);
        }
        return out;
    }
};