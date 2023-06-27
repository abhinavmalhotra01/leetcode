class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> ms;
        int curr=0;
        for(int i=0;i<heights.size()-1;i++){
            if(heights[i]<heights[i+1]){
                if(ms.size()<ladders){
                    ms.insert((heights[i+1]-heights[i]));
                }
                else if(ms.size() && heights[i+1]-heights[i]>*ms.begin()){
                    auto e=ms.begin();
                    curr+=*e;
                    // cout<<curr<<endl;
                    if(curr>bricks){
                        return i;
                    }
                    ms.erase(e);
                    ms.insert((heights[i+1]-heights[i]));
                }
                else{
                    curr+=heights[i+1]-heights[i];
                    // cout<<curr<<endl;
                    if(curr>bricks){
                        return i;
                    }
                }
            }
        }
        // if(heights[heights.size()-1]-heights[heights.size()-2])
        return heights.size()-1;
    }
};