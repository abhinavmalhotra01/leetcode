class KthLargest {
    priority_queue <int, vector<int>, greater<int>> gq;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(auto e:nums){
            if(gq.size()>=k){
                if(e>gq.top()){
                    gq.pop();
                    gq.push(e);
                }
            }else{
                gq.push(e);
            }
        }
    }
    
    int add(int val) {
        if(gq.size()>=n){
            if(gq.top()<val){
                gq.pop();
                gq.push(val);
            }
        }else{
            gq.push(val);
        }
        return gq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */