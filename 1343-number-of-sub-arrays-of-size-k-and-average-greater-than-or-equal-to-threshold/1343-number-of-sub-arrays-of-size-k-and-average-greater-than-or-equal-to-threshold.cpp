class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0,j=0;
        int currSum=0;
        int out=0;
        while(j<arr.size()){
            currSum+=arr[j];
            if(j-i+1 < k){
                j++;
            }
            else{
                if(currSum >= k*threshold){
                    out++;
                }
                currSum-=arr[i];
                i++;
                j++;
            }
        }
        return out;
    }
};