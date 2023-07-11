class Solution {
public:
    void rec(vector<vector<int>> &out, int start,vector<vector<int>> &graph, vector<int> &v )
    {
        v.push_back(start);
        if(start == graph.size()-1)
        {
            out.push_back(v);
        }
        else{
            for(auto i : graph[start])
            {
                rec(out,i,graph,v);
            }
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> out;
        vector<int> v;
        rec(out,0,graph,v);
        return out;
        
    }
};