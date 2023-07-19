class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int out=0;
        int las = INT_MIN;
        for(auto e:points){
            // cout<<e[0]<<" "<<e[1]<<" ";
            if(e[0] <= las){
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
        if(out==points.size()){return 1;}
        return points.size()-out;
    }
};