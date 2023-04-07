class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){            
            if(board[i][0]==1){
                q.push({i,0});
            }
            if(board[i][m-1]==1){
                q.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]==1){
                q.push({0,j});
            }
            if(board[n-1][j]==1){
                q.push({n-1,j});
            }
        }
        vector<int> diffr = {-1,1,0,0};
        vector<int> diffc = {0,0,-1,1};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            // cout<<i<<" "<<j<<endl;
            q.pop();
            vis[i][j]=1;
            for(int k=0;k<4;k++){
                int curr = i+diffr[k];
                int curr2 = j+diffc[k];
                if(curr<n && curr2<m && curr>=0 && curr2>=0){
                    if(!vis[curr][curr2] && board[curr][curr2]==1){
                        q.push({curr,curr2});
                        vis[curr][curr2]=1;
                    }
                }
            }
        }
        int out=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]==1){
                    out++;
                }
            }
        }
        return out;
    }
};