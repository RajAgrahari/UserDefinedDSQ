//https://leetcode.com/problems/design-parking-system/description/
class ParkingSystem {
public:
    int l=0,m=0,r=0;
    ParkingSystem(int big, int medium, int small) {
        l = small;
        m = medium;
        r = big;
    }
    
    bool addCar(int carType) {
        if(carType==3)
        {
           if(l==0)
           return false;
           else{
               l--;
               return true;
           }
        }
        else if(carType==2)
        {
            if(m==0)
            return false;
            else
            {
                m--;
                return true;
            }
        }
        else{
            if(r==0)
            return false;
            else{
                r--;
                return true;
            }
        }
        return true;
    }
};
