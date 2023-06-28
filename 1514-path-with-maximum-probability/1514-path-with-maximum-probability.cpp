class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double out=0;
        priority_queue<pair<double,int>> pq;
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            auto e=edges[i];
            adj[e[0]].push_back({e[1],succProb[i]});
            adj[e[1]].push_back({e[0],succProb[i]});
        }
        pq.push({1.0,start});
        vector<double>prob(n,0);
        prob[start]=1;
        while(!pq.empty()){
            auto e=pq.top();
            int currN = e.second;
            double currP = e.first;
            pq.pop();
            if(currN==end){return currP;}
            for(auto &e:adj[currN]){
                double nextP = e.second;
                int next = e.first;
                if(prob[next]<nextP*currP){
                    prob[next]=nextP*currP;
                    pq.push({nextP*currP,next});
                }
            }
        }
        return prob[end];
    }
};