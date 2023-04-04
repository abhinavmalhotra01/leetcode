class Solution {
    vector<string> out;
    unordered_map<int,string> m;
    void rec(int i , string curr , string digits){
        if(i>=digits.size()){
            out.push_back(curr);
            return ;
        }
        string c = m[digits[i]-'0'];
        for(int j=0;j<c.size();j++){
            curr.push_back(c[j]);
            rec(i+1,curr,digits);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        m[2]="abc";m[3]="def";m[4]="ghi";m[5]="jkl";m[6]="mno";m[7]="pqrs";m[8]="tuv";m[9]="wxyz";
        if(digits.size()==0){
            return out;
        }
        rec(0,"",digits);
        return out;
    }
};