class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0 , h = nums.size()-1;
        while( l+1 < nums.size() and nums[l] == nums[l+1]) {l++;}
        while( h >= 0 and nums[h] == nums[0] ) {h--;}
        int start = l , end = h;
        int left =l,right=h;
        int pv =-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]<nums[0]){
                pv=mid;right=mid-1;
            }else{
                left=mid+1;
            }
        }
        // cout<<pv<<endl;
        if(pv==-1){
            left =start;right=end;
        }else{
            if(target>nums[nums.size()-1]){
                left = 0;right=pv-1;
            }else{
                left=pv;right=nums.size()-1;
            }
        }
        while ( left <= right ){
            int mid = (left+right)/2;
            if( nums[mid] > target ) right = mid-1;
            else if( nums[mid] < target ) left = mid+1;
            else return true;
        }
        if(nums[0]==target || nums.back()==target){
            return true;
        }
        return false;
    }
};