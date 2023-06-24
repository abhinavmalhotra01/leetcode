class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int i=0,j=0;
        multiset<int> s;
        while(j<nums.size()){
            auto e = s.lower_bound(nums[j]);
            if(e!=s.end() && *e-nums[j]<=valueDiff){
                return true;
            }
            if(e!=s.begin() && nums[j]-*(--e)<=valueDiff){
                return true;
            }
            s.insert(nums[j]);
            if(j-i+1 > indexDiff){
                s.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};