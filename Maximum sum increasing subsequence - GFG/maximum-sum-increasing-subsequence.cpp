//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int rec(int i,int prev , vector<int>& nums,vector<vector<int>>& dp){
        if(i>=nums.size()){return 0;}
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int a = rec(i+1,prev,nums,dp),b=0;
        if(prev==-1 || nums[i]>nums[prev]){
            b=rec(i+1,i,nums,dp)+nums[i];
        }
        return dp[i][prev+1]=max(a,b);
        // return 0;
    }

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> nums;
	    for(int i=0;i<n;i++){
	        nums.push_back(arr[i]);
	    }
	    vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return rec(0,-1,nums,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends