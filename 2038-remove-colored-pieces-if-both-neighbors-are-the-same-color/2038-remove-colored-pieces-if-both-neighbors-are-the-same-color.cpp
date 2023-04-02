class Solution {
public:
    bool winnerOfGame(string colors) {
        int am = 0,bm=0;
        for(int i=1;i<colors.size()-1;i++){
            if(colors[i]=='A'){
                if(colors[i-1]==colors[i] && colors[i]==colors[i+1]){
                    am++;
                }
            }else {
                if(colors[i-1]==colors[i] && colors[i]==colors[i+1]){
                    bm++;
                }
            }
        }
        if(am==bm){
            return false;
        }
        return am>bm;
    }
};