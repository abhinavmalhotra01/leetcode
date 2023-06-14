class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int out =0;
        int i=0,j=0;
        // int fl=0,fl2=0;
        queue<int> q;
        while(i<nums.size() && j<nums.size()){
            if(nums[j]==0){
                q.push(j);
            }
            if(q.size()>k){
                out = max(out,j-i);
                int y = q.front();
                q.pop();
                // cout<<y<<" "<<j<<endl;
                i=y+1;
                j++;
                continue;
            }
            out = max(out,j-i+1);
            j++;
        }
        return out;
    }
};