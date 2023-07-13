class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int>m;
        for(int i=0;i<nums.size();i++){
            if(m.size()<k){
                m.insert(nums[i]);
            }else{
                if(nums[i]>*m.begin()){
                    m.erase(m.begin());
                    m.insert(nums[i]);
                }
            }
        }
        return *m.begin();
    }
};