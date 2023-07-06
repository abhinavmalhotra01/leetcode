class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1;i<=n;i++){
            s.push_back(i+'0');
        }
        int c=1;
        if(c==k){return s;}
        while(next_permutation(s.begin(),s.end())){
            // cout<<s<<" ";
            c++;
            if(c==k){
                return s;
            }
        }
        return "";
    }
};