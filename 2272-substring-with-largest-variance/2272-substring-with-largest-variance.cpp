class Solution {
public:
    int largestVariance(string s) {
        set<char> st;
        int out=0;
        for(auto e:s){st.insert(e);}
        for(int i=0;i<26;i++){
            char frs = i+'a';
            for(int j=0;j<26;j++){
                char scd = j+'a';
                if(!(st.count(scd)) || !(st.count(frs))){
                    continue;
                }
                int fc=0,sc=0,ch=0;
                for(auto e:s){
                    if(e==scd){sc++;}
                    if(e==frs){fc++;}
                    if(sc>0){
                        out=max(out,fc-sc);
                    }else{
                        if(ch){
                            out=max(out,fc-1);
                        }
                    }
                    if(sc>fc){
                        sc=0;fc=0;ch=1;
                    }
                }
            }
        }
        return out;
    }
};