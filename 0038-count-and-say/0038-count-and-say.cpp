class Solution {
public:
    string countAndSay(int n) {
        map<int,string> m;
        m[1]="1";
        for(int i=2;i<=n;i++){
            string s = m[i-1];
            // cout<<m[i-1]<<" "<<i-1<<endl;
            // cout<<s<<endl;
            string o;
            for(int j=0;j<s.size();j++){
                int c =1;
                while(j<s.size()-1 && s[j]==s[j+1]){
                    c++;j++;
                }
                o+=(c+'0');
                o+=s[j];
            }
            m[i]=o;
        }
        return m[n];
    }
};