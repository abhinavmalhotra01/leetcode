class Solution {
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> end;
        vector<vector<int>> out;
        for(int i=0;i<intervals.size();i++){
            if(!end.size()){
                end=intervals[i];  
            }
            else{
                if(intervals[i][0]<end[1]){
                    // cout<<end[1]<<" ";
                    end[1]=max(end[1],intervals[i][1]);
               }else if(intervals[i][0]==end[1]){
                    // cout<<end[1];
                    end[1]=intervals[i][1];
               }
                else{
                    out.push_back(end);
                    end=intervals[i];
                }
            }
        }
        out.push_back(end);
        return out;
    }
};