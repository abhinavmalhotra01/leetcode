class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> out;
        if(num%3){return out;}
        long long a = num/3*1ll;
        out={a-1,a,a+1};
        return out;
    }
};