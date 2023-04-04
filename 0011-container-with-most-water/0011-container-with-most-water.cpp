class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;
        int out =0;
        while(i<=j){
            int curr = min(height[i],height[j]);
            curr*=(j-i);
            out=max(out,curr);
            if(height[j]==min(height[i],height[j])){j--;}
            else{i++;}
        }
        return out;
    }
};