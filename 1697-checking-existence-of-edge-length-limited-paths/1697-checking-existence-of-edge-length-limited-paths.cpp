class DSU {
private:
    vector<int> parent, size; 
public:
    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    } 
public:
    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
public:
    void unionSize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) {
            return;
        }
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = queries.size();
        int w = edgeList.size();

        for(int i = 0; i < m; i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](vector<int>&a, vector<int>&b){
            return a[2] < b[2];
        });
        sort(edgeList.begin(), edgeList.end(), [](vector<int>&a, vector<int>&b){
            return a[2] < b[2];
        });
        
        DSU dsu(n);
        vector<bool> ans(m, false);
        int EdgeInd = 0, QueryInd = 0;
        while(QueryInd < m && EdgeInd < w){
            int maxLength = queries[QueryInd][2];
            int index = queries[QueryInd][3];
            int node1 = queries[QueryInd][0];
            int node2 = queries[QueryInd][1];
            while(EdgeInd < w && edgeList[EdgeInd][2] < maxLength){
                dsu.unionSize(edgeList[EdgeInd][0], edgeList[EdgeInd][1]);
                EdgeInd++;
            }
            if(dsu.findPar(node1) == dsu.findPar(node2)){
                ans[index] = true;
            }
            QueryInd++;
        }
        while(QueryInd < m){
            int index = queries[QueryInd][3];
            ans[index] = true;
            QueryInd++;
        }
        return ans;
    }
};