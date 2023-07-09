class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()){k=k%nums.size();}
        // for(int i=0;i<k;i++){
        //     swap(nums[i],nums[nums.size()-k+i]);
        // }
        // if(nums.size()==2*k){return;}
        // for(int i=k;i<nums.size()-1;i++){
        //     cout<<nums[i]<<" "<<nums[i+1]<<endl;
        //     swap(nums[i],nums[i+1]);
        // }
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};