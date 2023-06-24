class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tf) {
        int req=times[tf][0];
        sort(times.begin(),times.end());
        multiset<pair<int,int>> m;
        set<int> s;
        for(auto e:times){
            while(m.size() && (*m.begin()).first<=e[0]){
                s.insert((*m.begin()).second);
                m.erase(m.begin());
            }
            if(e[0] == req){
                break;
            }
            if(s.empty()){
                m.insert({e[1],m.size()});
            }else{
                m.insert({e[1],*s.begin()});
                s.erase(s.begin());
            }
        }
        if(s.empty()){
            return m.size();
        }
        return *s.begin();
    }
};