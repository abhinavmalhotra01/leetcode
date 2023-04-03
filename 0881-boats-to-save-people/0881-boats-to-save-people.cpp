class Solution {

public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int out=0;
        int j=0;
        // int lo=1,hi=1e9;
        for(int i=people.size()-1;i>=j;i--){
            if(people[i]+people[j]<=limit){out++;j++;}
            else{out++;}
        }
        return out;
    }
};