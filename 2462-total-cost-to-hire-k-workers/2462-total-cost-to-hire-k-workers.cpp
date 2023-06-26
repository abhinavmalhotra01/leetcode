class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        multiset<pair<int ,int>> ms;
        int j=0,h=costs.size()-1;
        while(j<candidates && j<costs.size()){ms.insert({costs[j],j});j++;}
        j--;
        while(h>=costs.size()-candidates && h>=0){if(ms.count({costs[h],h})){h--;continue;}ms.insert({costs[h],h});h--;}
        h++;
        long long out=0;
        int i=0;
        set<int> del;
        while(i<k && ms.size()){
            out+=(*ms.begin()).first;
            auto e = ms.begin();
            del.insert((*ms.begin()).second);
            if((*ms.begin()).second <=j){
                // cout<<j<<" j ";
                j++;
                if(j<costs.size() && !del.count(j) && !ms.count({costs[j],j})){ms.insert({costs[j],j});}
            }
            else if((*ms.begin()).second>=h){
                h--;
                if(h>=0 && !del.count(h) && !ms.count({costs[h],h})){ms.insert({costs[h],h});}
            }
            ms.erase(e);
            i++;
        }
        return out;
    }
};