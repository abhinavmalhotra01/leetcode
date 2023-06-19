class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int out =0;
       
        for(auto e:words){
             map<char,int> m;
            int fl=0;
            for(auto t:chars){m[t]++;}
                for(auto r:e){
                    if(m.count(r)==0){fl=1;}
                    else{m[r]--; if(m[r]==0){m.erase(r);}}
                }
            if(!fl){out+=e.size();}
        }
        return out;
    }
};