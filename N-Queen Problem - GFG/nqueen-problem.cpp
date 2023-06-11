//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool issafe(int col , int row , vector<vector<int>> &board , int n){
        
    
    for(int i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    
    for(int i=row,j=col;j>=0 && i>=0;j--,i--){
        if(board[i][j]){
            return false;
        }
    }
    
    for(int i=row,j=col; j>=0 && i<n; j--,i++){
        if(board[i][j]){
            return false;
        }
    }
    
        
        return true;
    }
    
    void addsol(vector<vector<int>> &board , int n , vector<vector<int>> &ans){
        
        vector<int> curr;
        
        for(int col = 0 ; col<n ;col++){
            for(int row = 0 ; row< n ;row++){
                if(board[row][col]==1){
                    // cout<<row<<" "<<col<<endl;
                    curr.push_back(row+1);
                }
            }
        }
        ans.push_back(curr);
    }
    
    void solve(int col , vector<vector<int>> &board ,int n , vector<vector<int>> &ans , vector<int> temp){
        if(col==n){
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<n;j++){
            //         cout<<board[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            addsol(board , n , ans );
            return ;
        }    
        
        for(int row = 0 ; row < n ; row++){
            
            if(issafe(col, row , board , n )){
                board[row][col] = 1 ;
                solve(col+1 , board , n , ans , temp);
                board[row][col] = 0;
                
            }
        }
    }
    
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
         vector<int> temp;
        if(n==1){
            temp.push_back(1);
            ans.push_back(temp) ;
            return ans;
        }
        vector<vector<int>> board(n,vector<int> (n,0));
        
       
        
        solve( 0 , board, n , ans , temp );
        
        return ans ;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends