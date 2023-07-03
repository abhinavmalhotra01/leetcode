class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int c=0;map<char,int> m,m2;
        if(s.size()!=goal.size()){return 0;}
        for(int i=0;i<s.size();i++){
            m[s[i]]++;m2[goal[i]]++;
            if(s[i]!=goal[i]){c++;}
        }
        if(!c){  
            return m.size()<s.size();
        }
        for(auto e:m){
            if(m2[e.first]!= e.second){
                return 0;
            }
        }
        return c==2 ;
    }
};