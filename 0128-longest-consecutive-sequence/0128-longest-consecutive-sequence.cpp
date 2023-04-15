class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0){return 0;}
        unordered_map<int,int> m;
        for(auto e:arr){m[e]++;}
        vector<int> nums;
        for(auto e : m){
            nums.push_back(e.first);
        }
        sort(nums.begin(),nums.end());
        int out =1;
        int curr=1;
        int maxi = *max_element(nums.begin(),nums.end());
        for(auto e:nums){
            if(m.count(e+1)>0){
                // cout<<e<<endl;
                curr++;
            }else{
                if(e==maxi){continue;}
                out=max(out,curr);
                // cout<<curr<<endl;
                curr=1;
            }
        }
        out=max(out,curr);
        return out;
    }
};