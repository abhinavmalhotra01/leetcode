class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string out;
        int i=0;
        for(;i<word1.size();i++){
            if(i>=word2.size()){
                out.push_back(word1[i]);
                continue;
            }
            out.push_back(word1[i]);
            out.push_back(word2[i]);
        }
        if(i<word2.size()){
            while(i<word2.size()){
                out.push_back(word2[i]);
                i++;
            }
        }
        return out;
    }
};