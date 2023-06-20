class Solution {
    int rec(int i,vector<vector<int>>& adj,int& cnt,long long int& ma){
        long long int l=0,r=0;
        if(adj[i].size()>0){
            l=rec(adj[i][0],adj,cnt,ma);
            // cout<<l<<" "<<i<<endl;
        }
        if(adj[i].size()>1){
            r=rec(adj[i][1],adj,cnt,ma);
            // cout<<r<<" "<<i<<endl;
        }
        long long int curr =1;
        if(l){
            curr*=l;
        }
        if(r){
            curr*=r;
        }
        long long int par = adj.size()-l-r-1;
        if(par){curr*=par;}
        if(curr>ma){
            // cout<<i<<" ";
            ma=curr;cnt=1;
        }
        else if(ma==curr){cnt++;}
        return l+r+1;
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        // vector<int> values(parents.size());
        vector<vector<int>> adj(parents.size());
        for(int i=1;i<parents.size();i++){
            adj[parents[i]].push_back(i);
        }
        int cnt=0;
        long long int ma=0;
        rec(0,adj,cnt,ma);
        return cnt;
    }
};