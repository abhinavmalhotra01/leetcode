// class Solution {
//     int check(int mid , vector<int>& nums, int x){
//         int curr=0;
//         int i=0,j=nums.size()-1;
//         while(i<j){
//             // cout<<i<<" "<<j<<" ";
//             if(nums[i]>nums[j] && x>=nums[i]){                
//                 x-=nums[i];
//                 // cout<<x<<endl;
//                 i++;
//                 curr++;
//                 if(!x){return curr<=mid;}
//             }else if(nums[i]<=nums[j] && x>=nums[j]){               
//                 x-=nums[j];
//                 // cout<<x<<endl;
//                 j--;
//                 curr++;
//                 if(!x){return curr<=mid;}
//             }else if(x<nums[i] && x>=nums[j]){
//                 x-=nums[j];
//                 j--;
//                 curr++;
//                 if(!x){return curr<=mid;}
//             }else if(x<nums[j] && x>=nums[i]){
//                 x-=nums[i];
//                 i++;
//                 curr++;
//                 if(!x){return curr<=mid;}
//             }else{
//                 break;
//             }
//         }
//         return curr<=mid && !x;
//     }
// public:
//     int minOperations(vector<int>& nums, int x) {
//         int l=-1,r=1e6;
//         int c=0;
//         while(l<r){
//             int mid = l+(r-l)/2;
//             if(check(mid,nums,x)){
//                 c=1;
//                 r=mid;
//             }else{
//                 l=mid+1;
//             }
//         }
//         if(!c){return -1;}
//         return l;
//     }
// };
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0,j=0,sum=0,mini=INT_MAX;
        int n= nums.size();
        int total=0;
        for(auto it:nums) total+=it;
        if(total < x) return -1;
        while(j< n) {
            sum+= nums[j];
            if(sum< total-x) j++;
            else if(sum==total-x) {
                mini= min(mini,n-(j-i+1));
                j++;
            }
            else if(sum>total-x) {
                while(sum>total-x) {
                    sum-=nums[i];
                    i++;
                }
                if(sum==total-x) mini= min(mini,n-(j-i+1));
                j++;
            }
        }
        return (mini==INT_MAX?-1:mini);
    }
};