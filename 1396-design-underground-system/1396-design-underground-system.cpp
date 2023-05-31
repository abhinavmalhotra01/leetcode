class UndergroundSystem {
    map<int,pair<string,int>> m1;
    map<pair<string,string>,pair<int,int>> m2;
public:
    UndergroundSystem() {
        // map<int,pair<string,int>> m1;
        // map<pair<string,string>,pair<int,int>> m2;
    }
    
    void checkIn(int id, string stationName, int t) {
        m1.insert({id,{stationName,t}});
    }
    
    void checkOut(int id, string d, int t) {
        string c = m1[id].first;
        int tg = m1[id].second;
        m1.erase(id);
        pair<string, string> e(c,d);
        if(m2.count(e)!=0){
            m2[e].first += t-tg;
            if(t!=tg){m2[e].second++;}            
        }else{
            if(t!=tg){m2.insert({e,{t-tg,1}});}     
        }
    }
    
    double getAverageTime(string c, string d) {
        pair<string,string> jh(c,d);
        double f = m2[jh].first;
        return f/(m2[jh].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */