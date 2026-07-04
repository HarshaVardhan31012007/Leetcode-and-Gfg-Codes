using ll=long long;
class UndergroundSystem {
public:
    unordered_map<ll,pair<ll,string>>checkInStation;
    unordered_map<string,unordered_map<string,pair<ll,ll>>>avgTimeHelper;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInStation[id]={t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation=checkInStation[id].second;
        int startTime=checkInStation[id].first;
        avgTimeHelper[startStation][stationName].first+=(t-startTime);
        avgTimeHelper[startStation][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        ll t=avgTimeHelper[startStation][endStation].first;
        ll c=avgTimeHelper[startStation][endStation].second;
        return (double)t/c;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */