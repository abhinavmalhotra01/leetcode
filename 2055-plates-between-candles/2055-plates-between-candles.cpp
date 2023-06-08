class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> cpref(s.size());
        vector<int>pref(s.size());
        if(s[0]=='*'){cpref[0]=0;pref[0]=1;}else{cpref[0]=1;pref[0]=0;}
        for(int i=1;i<s.size();i++){
            if(s[i]=='*'){cpref[i]=cpref[i-1];pref[i]=pref[i-1]+1;}
            else{
                cpref[i]=cpref[i-1]+1;
                pref[i]=pref[i-1];
            }
        }
        // for(auto e:cpref){cout<<e<<" ";}cout<<endl;
        vector<int> out;
        for(auto e:queries){
            int a = e[0];
            int b = e[1];
            if(s[a]=='*'){
                a=lower_bound(cpref.begin(),cpref.end(),cpref[a]+1)-cpref.begin();
            }
            if(s[b]=='*'){
                // cout<<b<<endl;
                b=upper_bound(cpref.begin(),cpref.end(),cpref[b]-1)-cpref.begin();
            }
            // cout<<a<<"  "<<b<<endl;
            if(a>b){out.push_back(0);}
            else{
                // if(b>pref.size() || a>pref.size()){
                //     out.push_back(0);continue;
                // }
                out.push_back(pref[b]-pref[a]);
            }
        }
        return out;
    }
};