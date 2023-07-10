class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto e:asteroids){
            if(s.size() && (s.top()*e)>=0){
                s.push(e);
            }else if(!(s.size())){
                s.push(e);
            }else{
                // cout<<s.top()<<" "<<e<<endl;
                if(s.top()<0 && e>0){s.push(e);continue;}
                while(s.size() && ((s.top()*e)<0) && abs(s.top())<abs(e) && s.top()>0 && e<0){
                    s.pop();
                }
                if(s.size() && ((s.top()*e)<0) && s.top()==-e){s.pop();continue;}
                if(s.size() && (s.top()*e)>=0){s.push(e);}
                if(!(s.size())){s.push(e);}
            }
        }
        vector<int> out;
        while(s.size()){
            out.push_back(s.top());
            s.pop();
        }
        reverse(out.begin(),out.end());
        return out;
    }
};