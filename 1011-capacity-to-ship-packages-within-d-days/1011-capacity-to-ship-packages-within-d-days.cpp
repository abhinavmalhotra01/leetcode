class Solution {
    int check(int mid , vector<int>& v , int days ){
        int curr =0;
        int i=0;
        while(i<v.size()){
            int c = v[i];
            if(c>mid){return 0;}
            while(i<v.size()-1 && c+v[i+1]<=mid){
                c+=v[i+1];
                i++;
            }
            // if(mid==2){cout<<i<<" "<<v[i]<<endl;}
            i++;
            curr++;
        }
        return curr<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l =1,r=1e9;
        while(l<r){
            int mid = l+(r-l)/2;
            if(check(mid,weights,days)){
                // cout<<out<<endl;
                // out=mid;
                // r=mid-1;
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};