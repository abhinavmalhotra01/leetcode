class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long score = 0;
        for(int i=0;i<k;i++){
            score += (long long)v[i].second;
            pq.push(v[i].second);
        }
        long long out = score*v[k-1].first;
        for(int i=k;i<n;i++){
            score+=(v[i].second - pq.top());
            pq.pop();
            pq.push(v[i].second);
            out=max(out,score*v[i].first);
        }
        return out;
    }
};