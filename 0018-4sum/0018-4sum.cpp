class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> out;
        // sort + 2ptr
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long curr=1ll*target-nums[i]-nums[j];
                int l=j+1,r=nums.size()-1;
                while(l<r){
                    long long int ava =nums[l]+nums[r];
                    if(ava<curr){l++;}
                    else if(ava>curr){r--;}
                    else{
                        vector<int> cur;
                        cur.push_back(nums[i]);
                        cur.push_back(nums[j]);
                        cur.push_back(nums[l]);
                        cur.push_back(nums[r]);
                        s.insert(cur);
                        l++;r--;
                    }
                }
            }
        }
        for(auto e:s){out.push_back(e);}
        return out;
    }
};