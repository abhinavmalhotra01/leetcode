class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){i++;}
            else{
                swap(nums1[i],nums2[j]);
                // cout<<nums1[i]<<" "<<nums2[j]<<endl;
                i++;
                int c=j;
                while(j<n-1 && nums2[j]>nums2[j+1]){swap(nums2[j],nums2[j+1]);j++;}
                j=c;
            }
            // if(nums2[j]==0){j++;}
        }
        // for(int i=0;i<m;i++){cout<<nums1}
        for(int i=m;i<m+n;i++){
            swap(nums1[i],nums2[i-m]);
        }
    }
};