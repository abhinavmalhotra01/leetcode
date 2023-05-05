class Solution {
public:
    int maxVowels(string s, int k) {
        int out =0;
        unordered_map<char,int> m;
        m['a']++; m['e']++;m['i']++;m['o']++;m['u']++;
        int i=0,j=0;
        int cnt=0;
        while(j<s.size()){
            if(j-i<k){
                if(m.count(s[j])){
                    cnt++;
                }
                j++;
            }
            else{
                out=max(out,cnt);
                if(m.count(s[i])){
                    cnt--;
                }
                if(m.count(s[j])){
                    cnt++;
                }
                j++;
                i++;
            }
        }
        out=max(out,cnt);
        return out;
    }
};