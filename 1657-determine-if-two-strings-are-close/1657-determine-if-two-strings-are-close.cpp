class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){return false;}
        map<char,int> s1,s2;
        for(int i=0;i<word1.size();i++){
            s1[word1[i]]++;
            s2[word2[i]]++;;
        }
        vector<int> v1,v2;
        for(auto e:s1){
            v1.push_back(e.second);
            if(!s2.count(e.first)){
                return 0;
            }
        }
        for(auto e:s2){
            v2.push_back(e.second);
            if(!s1.count(e.first)){
                return 0;
            }
        }
        sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
        return v1==v2;
    }
};