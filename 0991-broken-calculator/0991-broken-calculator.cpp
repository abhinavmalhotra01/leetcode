class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int curr=startValue;
        int out=0;
        while(target>startValue){
            // cout<<target<<endl;
            if(target%2){target++;out++;}
            // if(target==startValue){return out;}
            target/=2;
            out++;
        }
        // cout<<startValue<<" "<<target<<endl;
        out+=(startValue-target);
        return out;
    }
};