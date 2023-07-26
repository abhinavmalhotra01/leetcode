class Solution {
    int check(int mid , vector<int>& dist, double hour){
        double cur=0;
        for(int i=0;i<dist.size()-1;i++){
            double curt = (double)dist[i]/mid;
            cur+=ceil(curt);
        }
        cur+=(double)dist[dist.size()-1]/mid;
        // cout<<mid<<" "<<cur<<" "<<ceil(hour)<<endl;
        return cur<=(hour);
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,h=1e9,c=0;
        // cout<<check(3,dist,hour)<<endl;
        while(l<h){
            int mid = l+(h-l)/2;
            if(check(mid,dist,hour)){
                c=1;
                h=mid;
            }else{
                l=mid+1;
            }
        }
        if(!c){return -1;}
        return l;
    }
};