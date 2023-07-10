class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){return 1;}
        int c=0;
        if(dividend<0){c++;}
        if(divisor<0){c++;}
        // int out=0;
        // for(int i=0;i<31;i++){
        //     // int c = divisor;
        //     // cout<<c<<" ";
        //     if((divisor<<i)<=dividend){
        //         // cout<<(c<<1)<<endl;
        //         if((divisor<<i)<0){break;}
        //         // cout<<(divisor<<i)<<" ";
        //         out+=pow(2,i);
        //         if((divisor<<i)==dividend){
        //             if(c%2){
        //                 return -1*out;
        //             }
        //             return out;
        //         }
        //         cout<<out<<endl;
        //     }
        // }
        // if(c%2){out--;out*=-1;}
        // return out;
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int out=0;
        while(a>=b){
            int q=0;
            while(a>(b<<(q+1))){
                q++;
            }
            out+=pow(2,q);
            a-=(b<<q);
        }
        if(out==(1<<31) && !(c%2)){return INT_MAX;}
        return c%2 ? -out : out;
    }
};