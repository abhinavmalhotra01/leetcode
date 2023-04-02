class Solution {
    void dfs(string c1,string c2,map<string,vector<string>>& g, map<string,double>& edge,double& ans,map<string,int>& vis , bool& f){
        vis[c1]=1;
        
        if(f){return;}
        for(auto child : g[c1]){
            if(!vis[child]){
                ans *= edge[c1+"+"+child];
                if(c2==child){f=true;return;}
                dfs(child,c2,g,edge,ans,vis,f);
                if(f){return;}
                else{
                    ans /= edge[c1+"+"+child];
                }
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // edges (a->b) wt= values[i] ;
        map<string,vector<string>> g;
        map<string,double> edge;
        for(int i=0;i<equations.size();i++){
            string c1 = equations[i][0];
            string c2 = equations[i][1];
            edge[c1+"+"+c2]=values[i];
            edge[c2+"+"+c1]=1/values[i];
            g[c1].push_back(c2);
            g[c2].push_back(c1);
        }
        vector<double> out;
        for(int i=0;i<queries.size();i++){
            string c1 = queries[i][0];
            string c2 = queries[i][1];
            if(g.count(c1)==0 || g.count(c2)==0){
                out.emplace_back(-1);
                continue;
            }
            map<string,int> vis;
            double ans = 1;
            bool f = false;
            if(c1==c2){f=true;}
            dfs(c1,c2,g,edge,ans,vis,f);
            if(f){out.emplace_back(ans);}
            else{out.emplace_back(-1);}
        }
        return out;
    }
};