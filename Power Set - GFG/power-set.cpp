//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void rec(vector<string>& out , int i , string &s , string curr , int sz){
        if(i==sz){
            if(curr==""){return;}
            out.push_back(curr);
            return;
        }
        curr.push_back(s[i]);
        rec(out,i+1,s,curr,sz);
        curr.pop_back();
        rec(out,i+1,s,curr,sz);
    }
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> out;
		    rec(out,0,s,"",s.size());
		    sort(out.begin(),out.end());
		    return out;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends