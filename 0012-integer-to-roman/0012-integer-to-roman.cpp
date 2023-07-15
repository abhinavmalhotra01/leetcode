class Solution {
public:
    string intToRoman(int num) {
        // map<int,string> m;
        vector<pair<int,string>> v={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        string out;
        for(int i=v.size()-1;i>=0;i--){
            while(num>=v[i].first){
                out+=v[i].second;
                num-=v[i].first;
            }
        }
        return out;
    }
};