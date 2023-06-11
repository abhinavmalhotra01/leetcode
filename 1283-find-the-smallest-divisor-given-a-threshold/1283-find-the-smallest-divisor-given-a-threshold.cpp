class Solution {
    int check(int mid , vector<int>& nums,int th){
        double cur=0;
        for(auto e:nums){
            if(e/mid != e/(double)mid){
                cur+= e/mid;
                cur++;
            }else{
                cur+=e/mid;
            }
        }
        return cur<=th;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=1e9;
        while(l<r){
            int mid = l+(r-l)/2;
            if(check(mid,nums,threshold)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};