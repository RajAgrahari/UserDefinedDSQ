//https://leetcode.com/problems/design-underground-system/description/
class UndergroundSystem {
public:
    map<pair<string,string>,pair<int,double>> mp1;
    map<int,pair<string,int>> mp2;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        mp2[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        int time = t-mp2[id].second;
        int trips = mp1[{mp2[id].first,stationName}].first; 
        double avg = mp1[{mp2[id].first,stationName}].second; 
        double new_avg = (trips*avg + time)/(trips+1);
        mp1[{mp2[id].first,stationName}] = {trips+1,new_avg};
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        return mp1[{startStation,endStation}].second;
    }
};
