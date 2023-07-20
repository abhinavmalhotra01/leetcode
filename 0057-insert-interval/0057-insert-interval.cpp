class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> out;
        int is=0;
        for(int i=0;i<intervals.size();i++){
            auto e=intervals[i];
            if(e[1]>=newInterval[0] && e[0]<=newInterval[0]){
                is=1;
                if(newInterval[1]>e[1]){
                    e[1]=newInterval[1];
                    // i++;
                    while(i<intervals.size()){
                        // cout<<i<<endl;
                        if(intervals[i][0]<=e[1]){
                            e[1]=max(intervals[i][1],e[1]);
                        }else{ out.push_back({intervals[i][0],intervals[i][1]});;}
                        i++;
                    }
                    out.push_back({e[0],e[1]});
                }else{
                    out.push_back({e[0],e[1]});
                }
            }else if(e[1]>=newInterval[0] && newInterval[0]<=e[0] && newInterval[1]>=e[0]){
                is=1;
                // cout<<"p";
                e[0]=newInterval[0];
                if(newInterval[1]>e[1]){
                    e[1]=newInterval[1];
                    // i++;
                    while(i<intervals.size()){
                        // cout<<i<<endl;
                        if(intervals[i][0]<=e[1]){
                            e[1]=max(intervals[i][1],e[1]);
                        }else{ out.push_back({intervals[i][0],intervals[i][1]});;}
                        i++;
                    }
                    out.push_back({e[0],e[1]});
                }else{
                    out.push_back({e[0],e[1]});
                }
            }
            else{
                out.push_back({e[0],e[1]});
            }
        }
        if(!is){
            // cout<<"a";
            out.push_back(newInterval);
        }
        sort(out.begin(),out.end());
        return out;
    }
};