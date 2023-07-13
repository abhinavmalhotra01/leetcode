class Solution {
vector<int> topsort_bfs(vector<int>adj[] , int v){
	int indegree[v];
    for(int i=0;i<v;i++){indegree[i]=0;}
	for(int i=0;i<v;i++){
		for(auto it : adj[i]){
			indegree[it]++;
		}
	}
	queue<int> q;
	// indegree ready
	for(int i=0;i<v;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	vector<int> order;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		order.push_back(node);
		for(auto it : adj[node]){
			indegree[it]--;
			if(indegree[it]==0){
				q.push(it);
			}
		}
	}
	return order;
}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<int> adj[];
        // for(int i=0;i<prerequisites.size();i++){
        //     for(int j=0;j<prerequisites[0].size();j++){
        //         adj[i].push_back(j);
        //         adj[j].push_back(i);
        //     }
        // }
        //vector<vector<int>> adj;
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<int> order = topsort_bfs(adj,numCourses);
        if(order.size()==numCourses){return true;}
        return false;
    }
};