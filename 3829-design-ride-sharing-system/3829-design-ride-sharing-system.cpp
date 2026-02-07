class RideSharingSystem {
public:
    set<pair<int,int>>rider;
    set<pair<int,int>>driver;
    unordered_map<int,int>mpp;
    int time;
    RideSharingSystem() {
        time=0;
    }
    
    void addRider(int riderId) {
        rider.insert({time,riderId});
        mpp[riderId]=time;
        time++;
    }
    
    void addDriver(int driverId) {
        driver.insert({time,driverId});
        time++;
    }
    
    vector<int> matchDriverWithRider() {
        if(!driver.empty()&&!rider.empty()){
            int d=(driver.begin()->second);
            int r=(rider.begin()->second);
            mpp.erase(rider.begin()->second);
            driver.erase(driver.begin());
            rider.erase(rider.begin());
            return {d,r};
        }
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        if(mpp.count(riderId)){
            rider.erase({mpp[riderId],riderId});
            mpp.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */