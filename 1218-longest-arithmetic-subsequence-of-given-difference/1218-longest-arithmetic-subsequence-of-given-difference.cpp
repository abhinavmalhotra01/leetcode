class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // if(difference<0){difference*=-1;reverse(arr.begin(),arr.end());}
        vector<int> dp(arr.size());
        if(arr.size()==2){
            if(abs(arr[0]-arr[1])==difference){
                return arr.size();
            }else{
                return 1;
            }
        }else if(arr.size()<2){return arr.size();}
        map<int,int> m;
        // for(int i=0;i<arr.size();i++){
            // if(m.count(arr[i])){continue;}
            // m[arr[i]]=i;
        // }
        int out=0;
        for(int i=0;i<arr.size();i++){
            if(m.count((arr[i]-difference))){
                dp[i]=dp[m[arr[i]-difference]]+1;
            }else{
                dp[i]=1;
            }
            m[arr[i]]=i;
            out=max(out,dp[i]);
        }
        return out;
    }
};