class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int i=0;
        for(auto e:nums){
            i^=e;
        }
        // cout<<i<<endl;
        // for(auto e:nums){
        //     if((i^e)!=0){
        //         // cout<<(i^e)<<" ";
        //         out.push_back(e);
        //     }
        // }
        int b=1;
        while(1){
            if(i & b){break;}
            b=b<<1;
        }
        int a=0;
        for(auto e:nums){
            if(e&b){
                a^=e;
            }
        }
        return {a,a^i};
    }
};