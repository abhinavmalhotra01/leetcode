class Solution {
public:
    string reverseWords(string s) {
        string out;
        int i=s.size()-1;
        while(i>=0){
            while(i>=0 && s[i]==' '){i--;}
            // i++;
            string c;
            while(i>=0 && s[i]!=' '){
                c+=s[i];i--;
            }
            while(i>=0 && s[i]==' '){i--;}
            i++;
            reverse(c.begin(),c.end());
            out+=c;
            if(i==0){i--;continue;}
            out+=' ';
            i--;
        }
        return out;
    }
};