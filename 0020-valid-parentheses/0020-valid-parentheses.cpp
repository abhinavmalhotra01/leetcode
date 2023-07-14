class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        for(auto e:st){
            if(e=='(' || e=='{' || e=='['){
                s.push(e);
            }
            else if(e==')'){
                if(!(s.size())){
                    return 0;
                }else{
                    if(s.top()!='('){
                        return 0;
                    }else{
                        s.pop();
                    }
                }                
            }
            else if(e=='}'){
                if(!(s.size())){
                    return 0;
                }else{
                    if(s.top()!='{'){
                        return 0;
                    }else{
                        s.pop();
                    }
                }                
            }
            else if(e==']'){
                if(!(s.size())){
                    return 0;
                }else{
                    if(s.top()!='['){
                        return 0;
                    }else{
                        s.pop();
                    }
                }                
            }
        }
        return s.size()==0;
    }
};