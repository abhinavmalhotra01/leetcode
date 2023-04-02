class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto e:arr){m[e]++;}
        vector<pair<int,int>> v;
        for(auto &e:m){
            v.push_back({e.second,e.first});
        }
        sort(v.begin(),v.end());
        int i;
        for(i=0;i<v.size();++i)
        {
            if(v[i].first<=k){
                k-=v[i].first;
            }
            else{
                break;
            }
        }
        return m.size()-i;
    }
};