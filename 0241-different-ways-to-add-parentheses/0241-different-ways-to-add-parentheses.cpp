class Solution {
    // void rec(int i,string s,vector<int>& out){
    //     if(i>)
    // }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> out;
        for(int i=0;i<expression.size();i++){
            char cur = expression[i];
            if(cur=='+' || cur=='-' || cur=='*'){
                vector<int> l = diffWaysToCompute(expression.substr(0,i));
                vector<int> r = diffWaysToCompute(expression.substr(i+1));
                for (auto e : l) {
                    for (auto f : r) {
                        if (cur == '+')
                            out.push_back(e + f);
                        else if (cur == '-')
                            out.push_back(e- f);
                        else
                            out.push_back(e * f);    
                    }
                }
            }
        }
        if(!out.size()){
            out.push_back(stoi(expression));
        }
        return out;
    }
};