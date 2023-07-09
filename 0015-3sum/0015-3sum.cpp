class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int c=-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(!(i!=j && j!=k && i!=k)){j++;k--;continue;}
                if(nums[j]+nums[k]<c){j++;}
                else if(nums[j]+nums[k]>c){k--;}
                else{
                    vector<int> cur;
                    cur.push_back(nums[i]);
                    cur.push_back(nums[j]);
                    cur.push_back(nums[k]);
                    out.push_back(cur);
                    while(j<nums.size()-1 && nums[j]==nums[j+1]){j++;}
                    while(k>0 && nums[k]==nums[k-1]){k--;}
                    j++;k--;   
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]){i++;}
        }
        return out;
    }
};