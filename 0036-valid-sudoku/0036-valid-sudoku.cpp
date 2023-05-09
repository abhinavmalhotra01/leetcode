class Solution {
    bool ok(vector<vector<char>>& board, int i , int j , char c){
        // cout<<c;
        for(int a=0;a<9;a++){
            if(board[a][j]==c){
                if(i==a){continue;}
                // cout<<a<<" "<<j;
                // cout<<"a";
                return false;
            }
            if(board[i][a]==c){
                if(j==a){continue;}
                // cout<<"b";
                return false;
            }
            int x = (3*(i/3))+a/3;
            int y = (3*(j/3))+a%3;
            if(i==x && y==j){continue;}
            if(board[x][y]==c){
                // cout<<"c";
                return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(!ok(board,i,j,board[i][j]) && board[i][j]!='.'){
                    // cout<<board[i][j]<<i<<" "<<j;
                    return false;
                }
            }
        }
        return true;
    }
};