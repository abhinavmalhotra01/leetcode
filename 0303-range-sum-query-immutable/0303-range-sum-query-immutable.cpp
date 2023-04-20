class NumArray {
    vector<int> pref;
    int n;
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        pref.resize(2*n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){pref[i]=pref[i-1]+nums[i];}
        // for(int i=0;i<n;i++){cout<<pref[i]<<endl;}
    }
    
    int sumRange(int left, int right) {
        if(left){return pref[right]-pref[left-1];}
        return pref[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */