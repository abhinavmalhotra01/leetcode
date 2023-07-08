class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        // priority_queue<int> pq;
        // pq.push(nums[0]);
        int ma=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(ma>nums[i+1] ){
                return 0;
            }
            ma=max(ma,nums[i]);
        }
        return 1;
    }
};