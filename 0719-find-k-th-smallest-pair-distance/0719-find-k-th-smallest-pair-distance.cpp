class Solution {
    int check(int mid , vector<int>& nums,int k){
        int cur=0;
        int i=0,j=0;
        while(j<nums.size() || i<nums.size()){
            while(j<nums.size() && abs(nums[i]-nums[j])<=mid){
                j++;
            }
            cur+=(j-i-1);
            i++;
        }
        return cur>=k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int l=0,r=1e9;
        sort(nums.begin(),nums.end());
        while(l<r){
            int mid = l+(r-l)/2;
            if(check(mid,nums,k)){
                r=mid;
            }else{
                // cout<<mid<<endl;
                l=mid+1;
            }
        }
        return l;
    }
};