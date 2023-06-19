class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> pref(hours.size()+1);
        pref[0]=0;
        for(int i=1;i<=hours.size();i++){
            pref[i]=pref[i-1]+(hours[i-1]>8 ? 1 : -1);
        }
        stack<int> s;
        for(int i=0;i<=hours.size();i++){
            if(s.empty() || pref[s.top()]>pref[i]){
                s.push(i);
            }
        }
        // cout<<s.top()<<endl;
        int out =0;
        for(int i=hours.size();i>=0;i--){
            while(!s.empty() && pref[s.top()]<pref[i]){
                out=max(out,i-s.top());
                s.pop();
            }
        }
        return out;
    }
};