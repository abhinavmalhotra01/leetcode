class Solution {
public:
    double average(vector<int>& salary) {
        int out =0;
        int mi = *min_element(salary.begin(),salary.end());
        int ma = *max_element(salary.begin(),salary.end());
        for(auto e:salary){
            if(e==mi || e==ma){continue;}
            out+=e;
        }
        if(salary.size()==2){return 0;}
        return (double)out/(salary.size()-2);
    }
};