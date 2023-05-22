#define pi pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
map<int,int> f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        priority_queue<pi, vector<pi>, greater<pi> > pq; 

  for(auto e : f){
      pq.push({e.second,e.first});
      if(pq.size()>k){ pq.pop();}
      
  }
        vector<int>out;
  while(pq.size()){
      out.push_back(pq.top().second );
  pq.pop();
  }
        return out;}
}; 