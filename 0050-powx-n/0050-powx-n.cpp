class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){return 1;}
        double curr = myPow(x,n/2);
        if(n%2 && n>0){
            return curr*curr*x;
        }else if(n%2 && n<0){
            return curr*curr/x;
        }
        return curr*curr;
    }
};