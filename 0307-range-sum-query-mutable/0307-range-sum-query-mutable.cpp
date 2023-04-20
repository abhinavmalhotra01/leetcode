class NumArray {
    int n; 
    vector<int>t;
    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2+1, tl, tm);
            build(a, v*2+2, tm+1, tr);
            t[v] = t[v*2+1] + t[v*2+2];
        }
    }
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
            return sum(v*2+1, tl, tm, l, min(r, tm))
                + sum(v*2+2, tm+1, tr, max(l, tm+1), r);
    }
    void update2(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update2(v*2+1, tl, tm, pos, new_val);
        else
            update2(v*2+2, tm+1, tr, pos, new_val);
        t[v] = t[v*2+1] + t[v*2+2];
    }
}
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        t.resize(4*n,0);
        build(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        update2(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */