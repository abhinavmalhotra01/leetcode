class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int out=0;
        int las = INT_MIN;
        for(auto e:intervals){
            // cout<<e[0]<<" "<<e[1]<<" ";
            if(e[0] < las){
                // cout<<e[0];
                // out++;
                if(las>e[1]){
                    out++;
                    las=e[1];
                }else{
                    out++;
                }
            }else{
                las=e[1];
            }
            // cout<<endl;
        }
        return out;
    }
};