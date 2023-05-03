class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(auto e:nums1){m1[e]++;}
        for(auto e:nums2){m2[e]++;}
        vector<vector<int>> out;
        vector<int>v1,v2;
        for(auto e:m1){if(m2.count(e.first)==0){v1.push_back(e.first);}}
        for(auto e:m2){if(m1.count(e.first)==0){v2.push_back(e.first);}}
        out.push_back(v1);
        out.push_back(v2);
        return out;
    }
};