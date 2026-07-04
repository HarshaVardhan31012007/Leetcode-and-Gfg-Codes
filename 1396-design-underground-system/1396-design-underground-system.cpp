// using ll=long long;
// class UndergroundSystem {
// public:
//     unordered_map<ll,pair<ll,string>>checkInStation;
//     unordered_map<string,unordered_map<string,pair<double,ll>>>avgTimeHelper;
//     UndergroundSystem() {
        
//     }
    
//     void checkIn(int id, string stationName, int t) {
//         checkInStation[id]={t,stationName};
//     }
    
//     void checkOut(int id, string stationName, int t) {
//         string startStation=checkInStation[id].second;
//         int startTime=checkInStation[id].first;
//         checkInStation.erase(id);
//         avgTimeHelper[startStation][stationName].first+=(t-startTime);
//         avgTimeHelper[startStation][stationName].second++;
//     }
    
//     double getAverageTime(string startStation, string endStation) {
//         double t=avgTimeHelper[startStation][endStation].first;
//         ll c=avgTimeHelper[startStation][endStation].second;
//         return t/c;
//     }
// };

// /**
//  * Your UndergroundSystem object will be instantiated and called as such:
//  * UndergroundSystem* obj = new UndergroundSystem();
//  * obj->checkIn(id,stationName,t);
//  * obj->checkOut(id,stationName,t);
//  * double param_3 = obj->getAverageTime(startStation,endStation);
//  */


using ll=long long;
class UndergroundSystem {
public:
    unordered_map<ll,pair<ll,string>>checkInStation;
    unordered_map<string,pair<double,ll>>avgTimeHelper;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInStation[id]={t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation=checkInStation[id].second;
        int startTime=checkInStation[id].first;
        auto &temp=avgTimeHelper[startStation+" "+stationName];
        temp.first+=(t-startTime);
        temp.second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &temp=avgTimeHelper[startStation+" "+endStation];
        return temp.first/temp.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */