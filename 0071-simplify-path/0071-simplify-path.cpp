class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        for(int i=0;i<path.size();i++){
            // cout<<i<<endl;
            if(path[i]=='.'){
                
                int j=i;
                while(path[j]=='.'){j++;}
                // cout<<j<<i<<endl;
                if(j-i==1 && path[j]!='/' && path[i-1]=='/' && j!=path.size()){st.push(path[i]);continue;}
                else if(j-i>2){
                    // cout<<j<<endl;
                    for(int k=i;k<j;k++){st.push(path[k]);}
                    i=j-1;
                } 
                else if(j-i==2 && path[j]=='/' && path[i-1]=='/'){
                    // cout<<path[i-1]<<endl;
                    // cout<<j<<endl;
                    if(st.top()=='/'){st.pop();}
                    while(!st.empty() && st.top()!='/'){st.pop();}
                    i=j-1;
                }else if(j-i==2 && path[j]=='/'){
                    for(int k=i;k<j;k++){st.push(path[k]);}
                    i=j-1;
                }
                else if(j<path.size()-1 && path[j]!='/'){
                    for(int k=i;k<j;k++){st.push(path[k]);}
                    i=j-1;
                }else if(j>path.size()-1 && j-i==2 && path[i-1]=='/'){
                    cout<<i<<endl;
                    if(st.top()=='/'){st.pop();}
                    while(!st.empty() && st.top()!='/'){st.pop();}
                    i=j-1;
                }else if(j>path.size()-1 && j-i==2){
                    for(int k=i;k<j;k++){st.push(path[k]);}
                    i=j-1;
                }
                else if(path[i-1]!='/' &&j<path.size()-1 && path[j]=='/'){
                    cout<<i<<" "<<j<<endl;
                    for(int k=i;k<j;k++){st.push(path[k]);}
                    i=j-1;
                }else{continue;}
            }
            else{
                // cout<<i<<endl;
                if(!st.empty() && st.top()=='/' && path[i]!='/'){
                    st.push(path[i]);
                }else if(!st.empty() && st.top()!='/'){st.push(path[i]);}
                else if(st.empty()){st.push(path[i]);}
            }
            // cout<<i<<endl;
        }
        if(st.empty()){return "/";}
        string out;
        while(!st.empty()){out.push_back(st.top());st.pop();}
        reverse(out.begin(),out.end());
        if(out[out.size()-1]=='/' && out.size()!=1){out.pop_back();}
        return out;
    }
};