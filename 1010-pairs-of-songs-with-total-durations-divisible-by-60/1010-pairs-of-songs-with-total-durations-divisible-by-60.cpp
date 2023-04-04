class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> m;
        int out =0;
        
        // time[i]<=500 -> brute force -> 60*20 max
        // worked :) hehehe 
        /*
        for(auto e:time){m[e]++;}
        for(int i=0;i<time.size();i++){
            // cout<<m[time[i]]<<endl;
            m[time[i]]--;
            // cout<<m[time[i]]<<endl;
            if(m[time[i]]==0){m.erase(time[i]);}
            for(int j=0;j<20;j++){
                if(m.count(60*j - time[i])){
                    // cout<<time[i]<<" "<<(60*j-time[i])<<endl;
                    out+=m[60*j-time[i]];
                }
            }
        }
        */
        
        for(int i=0;i<time.size();i++){
            int curr = time[i]%60;
            if(curr==0){
                out+=m[0];
            }else{
                out+=m[60-curr];
            }
            m[curr]++;
        }
        return out;
    }
};