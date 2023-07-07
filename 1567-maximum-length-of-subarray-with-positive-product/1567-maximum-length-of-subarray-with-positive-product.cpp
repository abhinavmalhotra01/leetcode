class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // int c=0,k=0;
        // for(auto e:nums){
        //     if(e<0){c++;}
        //     if(e==0){k=-1;}
        // }
        // if(c%2==0 && k!=-1){return nums.size();}
        // int out=0;
        // int prev=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         int k=i;
        //         if(prev==-1){prev=i;}
        //         else{
        //             out=max(out,i-prev-1);
        //             prev=i;
        //         }
        //         while(i<nums.size() && nums[i]!=0){
        //             i++;
        //         }
        //         out=max(out,i-k-1);
        //     }else if(nums[i]<0){
        //         int k=i;                
        //         if(prev!=-1){
        //             // cout<<i-prev-1<<" "<<i<<endl;
        //             out=max(out,i-prev-1);
        //         }
        //         while(i<nums.size() && nums[i]!=0){
        //             i++;
        //         }
        //         out=max(out,i-prev-2);
        //         out=max(out,i-k-1);
        //     }
        // }
        int out=0;
        vector<pair<int,int>> zeroes;
        int prev=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeroes.push_back({prev,i});
                prev=i+1;
            }
        }
        zeroes.push_back({prev,nums.size()});
        for(auto& e :zeroes){
            vector<int> curr;
            for(int i=e.first;i<e.second;i++){
                if(nums[i]<0){curr.push_back(i);}
            }
            if(curr.size()%2==0){out=max(out,e.second-e.first);}
            else{
                out=max({out,e.second-curr[0]-1,curr[curr.size()-1]-e.first});
            }
        }
        return out;
    }
};