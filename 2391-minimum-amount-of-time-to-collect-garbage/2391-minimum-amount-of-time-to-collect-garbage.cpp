class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int out=0;
        int m=-1,g=-1,p=-1;
        for(int i=0;i<garbage.size();i++){
            for(auto f:garbage[i]){
                if(f=='M'){m=i;}
                if(f=='G'){g=i;}
                if(f=='P'){p=i;}
            }
        }
        // out+=garbage.size();
        if(m>-1){
            for(auto f:garbage[0]){
                if(f=='M'){out++;}
            }
        }
        if(g>-1){
            for(auto f:garbage[0]){
                if(f=='G'){out++;}
            }
        }
        if(p>-1){
            for(auto f:garbage[0]){
                if(f=='P'){out++;}
            }
        }
        for(int i=1;i<garbage.size();i++){
            if(i>m && i>p && i>g){break;}
            if(i<=m){out+=travel[i-1];}
            if(i<=g){out+=travel[i-1];}
            if(i<=p){out+=travel[i-1];}
            out+=garbage[i].size();
        }
        return out;
    }
};