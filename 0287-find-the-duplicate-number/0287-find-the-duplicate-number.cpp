class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(32,0);
        int n=nums.size()-1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<32;j++){
                if((1<<j)&i){
                    v[j]++;
                }
            }
        }
        vector<int> v2(32);
        for(int i=0;i<=n;i++){
            int a = nums[i];
            // cout<<a<<endl;
            for(int j=0;j<32;j++){
                // n & (1 << k)
                if((1<<j)&a){
                    v2[j]++;
                }
            }
        }
        int out=0;
        for(int i=0;i<32;i++){
            // cout<<v[i]<<" "<<v2[i]<<endl;
            if(v[i]!=v2[i] && v2[i]>v[i]){
                out+= (1<<i);
            }
        }
        return out;
    }
};