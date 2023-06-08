class Solution {
    bool check(int mid , vector<int>& bloomDay,int k ,int m){
        int tot=0,curr=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                curr++;
            }else{curr=0;}
            if(curr==k){
                tot++;curr=0;
            }
        }
        // cout<<tot<<endl;
        return tot>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int out =-1;
        int l=0,h=1e9+10;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(mid,bloomDay,k,m)){
                out=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return out;
    }
};