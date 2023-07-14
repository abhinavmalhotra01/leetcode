class StockSpanner {
    // vector<int> v;
    // map<int,int> m;
    // int c=0;
    stack<pair<int,int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        // v.push_back(price);
        // c++;
        // for(auto e:v){
            // s.push(e);
        // }
        // s.push(price);
        int a=0;
        while(s.size() && price>=(s.top()).first){
            // cout<<s.top().first<<" "<<s.top().second<<" ";
            a+=s.top().second;
            s.pop();
        }
        // cout<<endl;
        // m.insert({c,a});
        // cout<<price<<" "<<s.size()<<endl;
        s.push({price,a+1});
        return a+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */