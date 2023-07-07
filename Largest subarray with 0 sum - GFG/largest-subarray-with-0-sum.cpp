//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        vector<int> pref(n);
        pref[0]=A[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+A[i];
        }
        int i=0,j=0;
        int out=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(pref[i]==0){
                out=max(out,i+1);
            }
            if(m.count(pref[i])){
                out=max(out,i-m[pref[i]]);
               // m[pref[i]]=i;
            }else{
                m.insert({pref[i],i});
            }
        }
        return out;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends