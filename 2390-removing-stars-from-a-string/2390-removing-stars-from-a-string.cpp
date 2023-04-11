class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){st.push(s[i]);}
            else{
                st.pop();
            }
        }
        string out;
        while(!st.empty()){out.push_back(st.top());st.pop();}
        reverse(out.begin(),out.end());
        return out;
    }
};