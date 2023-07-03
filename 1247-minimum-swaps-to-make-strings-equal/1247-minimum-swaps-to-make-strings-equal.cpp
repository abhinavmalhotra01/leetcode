class Solution {
public:
    int minimumSwap(string s1, string s2) {
        // map<char,int> m;
        int a=0,b=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x' && s2[i]=='y'){a++;}
            else if(s1[i]!=s2[i]){b++;}
            // m[s1[i]]++;m[s2[i]]++;
        }
        if((a+b)%2){return -1;}
        // for(auto e:m){if(e.second%2){return -1;}}
        int out=0;
        out+=(a/2)+(b/2);
        out+= a%2+b%2;
        return out;
    }
};