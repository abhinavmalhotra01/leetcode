class Solution {
public:
    string shortestPalindrome(string s) {
        // string t=s;
        // // reverse(t.begin(),t.end());
        // int i=0,j=s.size()-1;
        // // while(i<s.size() && j>=0 && s[i]==t[j]){
        // //     cout<<s[i]<<" "<<t[j]<<endl;
        // //     i++;j--;
        // // }
        // while(i<=j){
        //     if(s[i]==s[j]){
        //         i++;j--;
        //     }
        // }
        // string f = s.substr(i);
        // cout<<f<<endl;
        // reverse(f.begin(),f.end());
        // if(f.size()%2==0 && s.size()%2==0){f.pop_back();}
        // f+=s;
        // return f;
        // int n = s.size();
        // int i = 0;
        // for (int j = n - 1; j >= 0; j--) {
        //     if (s[i] == s[j])
        //         i++;
        // }
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        s+="#";
        s+=t;
        vector<int> lps(s.size(),0);
        for(int i=1;i<s.size();i++){
            int c = lps[i-1];
            while(c>0 && s[i]!=s[c]){
                c=lps[c-1];
            }
            if(s[i]==s[c]){
                ++c;
            }
            lps[i]=c;
        }
        return t.substr(0,n-lps[s.size()-1])+s.substr(0,n);
    }
};