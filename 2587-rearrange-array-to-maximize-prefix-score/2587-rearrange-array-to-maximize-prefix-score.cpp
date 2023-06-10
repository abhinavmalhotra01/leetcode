class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<int> a2;
        for(auto e:nums){
            if(e>0){a2.push_back(e);}
        }
        for(auto e:nums){
            if(e==0){a2.push_back(e);}
        }
        for(auto e:nums){
            if(e<0){a2.push_back(e);}
        }
        int out =0;
        vector<long long> pref(nums.size());
        sort(a2.rbegin(),a2.rend());
        pref[0]=a2[0];
        for(int i=1;i<nums.size();i++){
            pref[i]=a2[i]+pref[i-1];
        }
        for(auto e:pref){
            if(e>0){out++;}
            else{break;}
        }
        return out;
    }
};