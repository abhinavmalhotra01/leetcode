class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<long long, int>> n;
        int i=0;
        for(auto e:nums){
            string f = to_string(e);
            // cout<<f<<" ";
            vector<int> cur;
            for(auto d:f){
                // cout<<(d-'0')<<" ";
                int a = d-'0';
                // cout<<a<<" ";
                // cout<<mapping[a]<<" ";
                cur.push_back(mapping[a]);
            }
            // cout<<cur<<endl;
            reverse(cur.begin(),cur.end());
            long long curr=0;
            for(int i=0;i<cur.size();i++){
                curr+=(cur[i]*(long long)pow(10,i+1));
            }
            // cout<<curr<<" ";
            n.push_back({curr,i});
            i++;
        }
        // cout<<endl;
        sort(n.begin(),n.end());
        vector<int> out;
        for(auto e:n){
            // cout<<e.first<<" ";
            e.first=nums[e.second];
            out.push_back(e.first);
        }
        return out;
    }
};