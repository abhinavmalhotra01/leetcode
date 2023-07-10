class MapSum {
    map<string,int> m;
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(m.count(key)){
            m.erase(key);
        }
        m.insert({key,val});
    }
    
    int sum(string prefix) {
        int out=0;
        for(auto e:m){
            // cout<<e.first<<" "<<e.second<<endl;
            int c=0;
            if(prefix.size()>e.first.size()){continue;}
            for(int i=0;i<e.first.size();i++){
                if(e.first[i]!=prefix[i]){
                    break;
                }else{
                    c++;
                }
            }
            if(c==prefix.size()){
                out+=e.second;
            }
        }
        return out;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */