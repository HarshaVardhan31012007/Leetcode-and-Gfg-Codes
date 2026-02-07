// class RideSharingSystem {
// public:
//     set<pair<int,int>>rider;
//     set<pair<int,int>>driver;
//     unordered_map<int,int>mpp;
//     int time;
//     RideSharingSystem() {
//         time=0;
//     }
    
//     void addRider(int riderId) {
//         rider.insert({time,riderId});
//         mpp[riderId]=time;
//         time++;
//     }
    
//     void addDriver(int driverId) {
//         driver.insert({time,driverId});
//         time++;
//     }
    
//     vector<int> matchDriverWithRider() {
//         if(!driver.empty()&&!rider.empty()){
//             int d=(driver.begin()->second);
//             int r=(rider.begin()->second);
//             mpp.erase(rider.begin()->second);
//             driver.erase(driver.begin());
//             rider.erase(rider.begin());
//             return {d,r};
//         }
//         return {-1,-1};
//     }
    
//     void cancelRider(int riderId) {
//         if(mpp.count(riderId)){
//             rider.erase({mpp[riderId],riderId});
//             mpp.erase(riderId);
//         }
//     }
// };




class RideSharingSystem {
public:
    queue<int>rider;
    queue<int>driver;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
      rider.push(riderId);
    }
    
    void addDriver(int driverId) {
       driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
       if(!rider.empty()&&!driver.empty()){
          int a=rider.front();
          int b=driver.front();
          rider.pop();
          driver.pop();
          return {b,a};
       }
       return {-1,-1};
    }
    
    void cancelRider(int riderId) {
       queue<int>q2;
       while(!rider.empty()){
          if(rider.front()==riderId)
          rider.pop();
          else{
            q2.push(rider.front());
            rider.pop();
          }
       }
       while(!q2.empty()){
        rider.push(q2.front());
        q2.pop();
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