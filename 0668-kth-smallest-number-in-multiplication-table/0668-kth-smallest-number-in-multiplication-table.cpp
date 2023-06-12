class Solution {
    int check(int mid , int m ,int n,int k){
        int cur =0;
        for(int i=1;i<=n;i++){
            cur+= min(m,mid/i);
        }
        return cur>=k;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int l=1,r=m*n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(check(mid,m,n,k)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};