class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mid =INT_MIN;
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<mid){
                return 1;
            }
            else{
                while(s.size() && nums[i]>s.top()){
                    mid=s.top();s.pop();
                }
                s.push(nums[i]);
            }
        }
        return 0;
    }
};