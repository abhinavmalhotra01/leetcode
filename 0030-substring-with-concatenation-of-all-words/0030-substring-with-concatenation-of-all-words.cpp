class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int>mp;
        int ws=words.size();
        int wsz=words[0].size();
        for(auto w:words)mp[w]++;
        int window=ws*wsz;
        vector<int>ans;
        for(int i=0;i<s.size()-window+1;i++){
           unordered_map<string,int>seen;
           bool f=true;
           for(int j=0;j<ws;j++){
              string t=s.substr(i+j*wsz,wsz);
               seen[t]++;
               if(seen[t]>mp[t]){
                   f=false;
                   break;
               }
           }
           if(f)
           ans.push_back(i);

        }
        return ans;
    }
};