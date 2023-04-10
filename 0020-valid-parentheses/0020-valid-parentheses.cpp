class Solution {
public:
    bool isValid(string s) {
        if(s.size()==1){return false;}
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(st.empty()){
                    return false;
                }else if(s[i]==')'){
                    int c = st.top();
                    if(s[i]-c!=1){
                        return false;
                    }else{
                        st.pop();
                    }
                }else {
                    int c = st.top();
                    if(s[i]-c!=2){
                        return false;
                    }else{
                        st.pop();
                    }
                }
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()){return true;}
        return false;
    }
};