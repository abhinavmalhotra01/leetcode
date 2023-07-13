class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int out =0;
        stack<int> s;
        int MOD = 1e9+7;
        for(int i=0;i<=arr.size();i++){
            while(s.size() && (i==arr.size() || arr[s.top()]>=arr[i])){
                int cur = s.top();
                s.pop();
                int l = s.size() ? s.top() : -1;
                // int as =((i-cur)*(cur-l))%MOD;
                // // 
                // out=((out)+(as*arr[cur])%MOD)%MOD;
                // cout<<out<<endl;
                out=(out +(long long)arr[cur]*(i-cur)*(cur-l))%MOD;
            }
            s.push(i);
        }
        return out;
    }
};