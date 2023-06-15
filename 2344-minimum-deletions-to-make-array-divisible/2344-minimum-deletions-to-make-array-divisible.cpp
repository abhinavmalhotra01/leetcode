class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsD) {
        int ok =  numsD[0];
        // pririty_queue<int> pq;
        sort(nums.begin(),nums.end());
        for(int i=1;i<numsD.size();i++){
            ok=__gcd(ok,numsD[i]);
        }
        // int a = nums[0];
        int cnt =0;
        while(cnt<nums.size() && ok%nums[cnt]){
            cnt++;
        }
        if(cnt==nums.size()){return -1;}
        return cnt;
    }
};