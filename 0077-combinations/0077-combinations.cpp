class Solution {
    vector<vector<int>> out;
    void rec(int i ,int k,int n,vector<int> cur){
        if(cur.size()==k){
            out.push_back(cur);
            return;
        }
        // if(i>n){return ;}
        // cur.push_back(i);
        // rec(i+1,k,n,cur);
        // cur.pop_back();
        // rec(i+1,k,n,cur);
        for(int j=i;j<=n;j++){
            cur.push_back(j);
            rec(j+1,k,n,cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        rec(1,k,n,v);
        return out;
    }
};