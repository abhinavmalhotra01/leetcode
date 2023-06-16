class Solution {
    typedef long long ll;
    ll mod = 1e9+7;
    vector<vector<ll>> grid;
    int rec(vector<int>& nums){
        if(nums.size()==0 || nums.size()==1 || nums.size()==2){
            return 1;
        }
        vector<int> l,r;
        int curr = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<curr){
                l.push_back(nums[i]);
            }else{
                r.push_back(nums[i]);
            }
        }
        ll xl = rec(l)%mod;
        ll xr = rec(r)%mod;
        ll xz = grid[nums.size()-1][l.size()]%mod;
        
        return (((xl*xr)%mod)*xz)%mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        grid.resize(nums.size()+1);
        for(int i=0;i<=nums.size();i++){
            grid[i]=vector<ll>(i+1,1);
            for(int j=1;j<i;j++){
                grid[i][j] = (grid[i-1][j] + grid[i-1][j-1])%mod;
            }
        }
        return (rec(nums)-1)%mod;
    }
};