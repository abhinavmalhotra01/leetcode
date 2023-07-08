class RandomizedSet {
     vector<int> v;
    unordered_map<int,int> s;
public:
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(s.count(val)){return 0;}
        v.push_back(val);
        s.insert({val,v.size()-1});
        return 1;
    }
    
    bool remove(int val) {
        if(!(s.count(val))){return 0;}
        auto i = s[val];
        // swap(v[i],v[v.size()-1]);
        // s.erase(val);
        // cout<<i<<" ";
        // cout<<v[i]<<" "<<v[v.size()-1]<<endl;
        // v.pop_back();
        // s[v[i]]=i;
        // for(auto e:v){cout<<e<<" ";}
        // cout<<endl;
        int l = v.back();
        v[i]=l;
        v.pop_back();
        s[l]=i;
        s.erase(val);
        return 1;
    }
    
    int getRandom() {
        int i = (rand())%(v.size());
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */