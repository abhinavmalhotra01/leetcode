class Solution {
public:
    bool isRobotBounded(string instructions) {
        int curri=0,currj=0,pos=0;
        for(auto e:instructions){
            if(e=='G'){
                if(pos==0){currj++;}
                else if(pos==1 || pos==-3){curri--;}
                else if(pos==2 || pos==-2){currj--;}
                else if(pos==3 || pos==-1){curri++;}
            }else if(e=='L'){
                pos++;
                if(pos==4){pos=0;}
            }else{
                pos--;
                if(pos==-4){pos=0;}
            }
        }
        return !((!pos) && (curri!=0 || currj!=0));
    }
};