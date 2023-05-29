class ParkingSystem {
    int a,b,c;
public:
    ParkingSystem(int big, int medium, int small) {
        a=big;
        b=medium;
        c=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(!a){return false;}
            a--;
            return true;
        }
        if(carType==2){
            if(!b){return false;}
            b--;
            return true;
        }
        if(!c){return false;}
        c--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */