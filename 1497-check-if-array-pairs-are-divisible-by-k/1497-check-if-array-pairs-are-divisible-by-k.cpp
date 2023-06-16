class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        int out =0;
        for(auto e:arr){
            int curr = (e%k + k)%k;
            // cout<<curr<<" ";
            if(curr==0){
                // cout<<"n"<<" ";
                // cout<<m[0]<<""
                if(m.count(0)>0){
                    // cout<<"d";
                    out++;
                    m[0]--;
                    if(m[0]==0){m.erase(0);}
                }else{
                    m[0]++;
                }
            }
            else if(m.count(k-curr)>0){
                out++;
                m[k-curr]--;
                if(m[k-curr]==0){m.erase(k-curr);}
            }else{m[curr]++;}
            // cout<<m[0]<<" ";
        }
        // cout<<" "<<arr.size()<<" "<<out<<endl;
        return out==arr.size()/2;
    }
};