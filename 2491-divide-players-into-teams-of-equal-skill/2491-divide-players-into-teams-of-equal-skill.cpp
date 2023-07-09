class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0,j=skill.size()-1;
        int c = skill[0]+skill[skill.size()-1];
        while(i<j){
            if(skill[i]+skill[j]!=c){return -1;}
            i++;j--;
        }
        long long out=skill[0]*skill[skill.size()-1];
        i=1;j=skill.size()-2;
        while(i<j){
            out+=(skill[i]*skill[j]);
            i++;j--;
        }
        return out;
    }
};