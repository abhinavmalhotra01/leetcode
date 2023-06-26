class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = accumulate(begin(grid[0]), end(grid[0]), 0LL), bottomSum = 0;
        // cout<<topSum<<endl;
        long long out = LLONG_MAX;
        for (int i = 0; i < grid[0].size(); ++i) {
            topSum -= grid[0][i];
            // cout<<topSum<<endl;
            out = min(out, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }
        return out;
    }
};