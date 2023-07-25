class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,h=arr.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(mid>0 && arr[mid]>arr[mid-1] && mid<arr.size()-1 && arr[mid]>arr[mid+1] ){
                return mid;
            }
            else if(mid>0 && arr[mid]<arr[mid-1]){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return 0;
    }
};