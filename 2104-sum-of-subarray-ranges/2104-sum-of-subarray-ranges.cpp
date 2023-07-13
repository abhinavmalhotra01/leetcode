class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long out=0;
        stack<int> s;
        for(int i=0;i<=nums.size();i++){
            while(s.size() && (i==nums.size() || nums[s.top()]>=nums[i])){
                int cur=s.top();
                s.pop();
                int l = s.size() ? s.top() : -1;
                out-=(long long)nums[cur]*(i-cur)*(cur-l);
            }
            s.push(i);
        }
        // s.clear();
        while(s.size()){s.pop();}
        for(int i=0;i<=nums.size();i++){
            while(s.size() && (i==nums.size() || nums[s.top()]<=nums[i])){
                int cur=s.top();
                s.pop();
                int l = s.size() ? s.top() : -1;
                out+=(long long)nums[cur]*(i-cur)*(cur-l);
            }
            s.push(i);
        }
        return out;
    }
};