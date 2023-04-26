class Solution {
public:
    int addDigits(int num) {
        // int out =0;
        // string s = to_string(num);
        // while(s.size()>1){
        //     int curr = 0;
        //     for(auto e:s){
        //         curr+= e-'0';
        //     }
        //     s = to_string(curr);
        // }
        // return stoi(s);
        if(num==0){return 0;}
        if(num%9){return num%9;}
        return 9;
    }
};