class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<long long> pref(nums.size()+1);
        pref[0]=0;
        for(int i=1;i<=nums.size();i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
        int div = (2*k)+1;
        vector<int> out(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i<k){out[i]=-1;}
            else if(i>=nums.size()-k){out[i]=-1;}
            else{
                long long curr = pref[i]-pref[i-k]+pref[i+k+1]-pref[i+1]+nums[i];
                curr/=div;
                out[i]=curr;
            }
        }
        return out;
    }
};