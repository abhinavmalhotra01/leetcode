class Solution {
private:
    long long countSubarrays(vector<int>& nums, int maxi){
        int n = nums.size();
        long long cnt = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= maxi){
                cnt++;
            }
            else{
                ans += (cnt * (cnt + 1)) / 2;
                cnt = 0;
            }
        }
        ans += (cnt * (cnt + 1)) / 2;
        return ans;
    }
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        return countSubarrays(nums, right) - countSubarrays(nums, left - 1);
    }
};