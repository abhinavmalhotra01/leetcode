class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int out =0;
        for(int i=0;i<houses.size();i++){
            if(houses[i]<heaters[0]){
                out=max(out,heaters[0]-houses[i]);
                continue;
            }
            int y = upper_bound(heaters.begin(),heaters.end(),houses[i])-heaters.begin();
            if(y!=heaters.size()){
                out=max(out, min(abs(houses[i]-heaters[y]),abs(houses[i]-heaters[y-1])));
            }else{
                out=max(out, (abs(houses[i]-heaters[y-1])));
            }
        }
        return out;
    }
};