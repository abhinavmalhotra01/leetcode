class Solution {
    void rec(int i,vector<int>& nums , vector<int>& cur,vector<vector<int>>& out){
        if(i>=nums.size()){
            out.push_back(cur);
            // cur.clear();
            return;
        }
        cur.push_back(nums[i]);
        rec(i+1,nums,cur,out);
        cur.pop_back();
        rec(i+1,nums,cur,out);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> curr;
        rec(0,nums,curr,out);
        return out;
    }
};