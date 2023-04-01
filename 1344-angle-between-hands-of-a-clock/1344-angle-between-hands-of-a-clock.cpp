class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour*5)%60;
        h+= (double)(minutes)/12;
        // cout<<h<<endl;
        // h+=add;
        // cout<<h<<endl;
        float curr = abs(h-minutes);
        curr*=6;
        if(curr>180){curr = 360-curr;}
        return curr;
    }
};