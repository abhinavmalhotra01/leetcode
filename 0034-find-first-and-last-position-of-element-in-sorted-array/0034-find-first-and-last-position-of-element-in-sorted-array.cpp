class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=-1,b=-1;
        int l=0,h=nums.size()-1;
        while(l<=h){
            int m = (l+h)/2;
            // cout<<l<<" "<<h<<" "<<m<<endl;
            if(nums[m]==target){
                a=m;
                if(m>0 && nums[m]==nums[m-1]){
                    h=m-1;
                    // cout<<h<<" "<<"a"<<l<<endl;
                }else{
                    break;
                }
            }else if(nums[m]>target){
                h=m-1;
            }else{
                l=m+1;
                // cout<<m<<" "<<l<<endl;/
            }
        }
        // cout<<a<<endl;
        l=0,h=nums.size()-1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]==target){
                b=m;
                if(m<nums.size()-1 && nums[m]==nums[m+1]){
                    l=m+1;
                }else{break;}
            }else if(nums[m]>target){
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return {a,b};
    }
};