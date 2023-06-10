class Solution {
    int check(long long mid , int a ,int b,int c , int n){
        long long currA = mid/a;
        long long currB = mid/b;
        long long currC = mid/c;
        long long currAB = mid/((a*b*1ll)/__gcd(a,b));
        long long currAC = mid/((a*c*1ll)/__gcd(a,c));
        long long currBC = mid/((b*1ll*c*1ll)/__gcd(b,c));
        // cout<<currBC<<endl;
        long long currABC = mid/((a*1ll*((b*1ll*c)/(__gcd(b,c))))/__gcd(1ll*a,((b*1ll*c)/__gcd(1ll*b,1ll*c))));
        return (currA+currB+currC-currAB-currAC-currBC+currABC)>=n;
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l=1,r=10*1e9;
        while(l<r){
            long long mid = l+(r-l)/2;
            if(check(mid,a,b,c,n)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};