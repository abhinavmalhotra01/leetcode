class Solution {
public:
    int partitionString(string s) {
        int out =0;
        unordered_map<char,int> m;
        int i=0,j=0;
        while(j<s.size()){
            m[s[j]]++;
            if(m.size()==j-i+1){
                j++;
                continue;
            }else if(m.size()<j-i+1) {
                // cout<<i<<" "<<j<<endl;
                m.clear();
                i=j;
                out++;
            }else{j++;}
        }
        if(m.size()<j-i+1){out++;}
        return out;        
    }
};