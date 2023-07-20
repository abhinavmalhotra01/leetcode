//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int rec(int i,int w,vector<int>& values , vector<int>& weights,vector<vector<int>>& dp){
	if(i>=dp.size() || w>=dp[0].size()){
		return 0;
	}
	if(dp[i][w]!=-1){
		return dp[i][w];
	}
	int a = rec(i+1,w,values,weights,dp);
	int b =0;
	if(w+weights[i] <dp[0].size()){
		b=rec(i+1,w+weights[i],values,weights,dp)+values[i];
	}
	return dp[i][w]=max(a,b);
}
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<int> values;
        for(int i=0;i<n;i++)
        {values.push_back(val[i]);}
        vector<int> weights;
        for(int i=0;i<n;i++){weights.push_back(wt[i]);}
        vector<vector<int>> dp(n,vector<int>(w+1,-1));
	    return rec(0,0,values,weights,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends