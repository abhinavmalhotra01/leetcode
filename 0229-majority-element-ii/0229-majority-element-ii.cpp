class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cur1=INT_MIN,cur2=INT_MIN;int cnt1=0,cnt2=0;
        for(auto e:nums){
            if(!cnt1 && cur2!=e){cur1=e;cnt1++;}
            else if(!cnt2 && cur1!=e){cur2=e;cnt2++;}
            else if(cur1==e){cnt1++;}
            else if(cur2==e){cnt2++;}
            else{
                cnt1--;cnt2--;
            }
        }
        int a=0,b=0;
        for(auto e:nums){
            if(e==cur1){a++;}
            if(e==cur2){b++;}
        }
        // cout<<cur1<<" "<<cur2<<endl;
        // cout<<a<<" "<<b<<endl;
        if(a>nums.size()/3 && b>nums.size()/3){
            // cout<<a<<" ";
            return {cur1,cur2};
        }else if(a>nums.size()/3){
            return {cur1};
        }else if(b>nums.size()/3){
            return {cur2};
        }
        return {};
    }
};