class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> pref(gain.size());
        pref[0]=gain[0];
        for(int i=1;i<pref.size();i++){
            pref[i]=pref[i-1]+gain[i];
        }
        return max(0,*max_element(pref.begin(),pref.end()));
    }
};