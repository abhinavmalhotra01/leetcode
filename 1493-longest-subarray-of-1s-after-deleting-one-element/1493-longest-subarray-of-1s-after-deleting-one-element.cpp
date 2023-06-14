class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>> v;
        int fl=0;
        int mi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){fl=1;continue;}
            int a=i,b=i;
            while(i<nums.size() && nums[i]==1){
                i++;b++;
            }
            mi=max(mi,b-a);
            // cout<<b-1<<" "<<a<<endl;
            v.push_back({a,b-1});
        }
        int out =0;
        if(!v.size()){return out;}
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1].first - v[i].second ==2){
                // cout<<v[i].second<<" "<<v[i+1].first<<endl;
                out=max(out,v[i+1].second - v[i].first);
            }
            out=max(out,v[i].second-v[i].first+1);
        }
        if(fl){out=max(out,v[v.size()-1].second - v[v.size()-1].first +1);}
        if(!out && fl){
            return mi;
        }else if(!out && !fl){
            return nums.size()-1;
        }
        return out;
    }
};