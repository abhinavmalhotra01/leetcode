class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int out=0;
        unordered_map<int,int> m;
        // for(auto e:nums4){m[e]++;}
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         for(int k=0;k<nums3.size();k++){
        //             out+= (m.count(-nums1[i]-nums2[j]-nums3[k])) ? m[-nums1[i]-nums2[j]-nums3[k]] : 0;
        //         }
        //     }
        // }
        // return out;
        for(auto e:nums4){
            for(auto f:nums3){
                m[e+f]++;
            }
        }
        for(auto i:nums1){
            for(auto j:nums2){
                out+=(m.count(-i-j)) ? m[-i-j] :0;
            }
        }
        return out;
    }
};