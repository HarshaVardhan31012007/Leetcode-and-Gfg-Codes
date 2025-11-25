class Solution {
public: 
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int dist=0;
        int fuel=startFuel;
        int stops=0;
        priority_queue<pair<int,int>>pq;
        int i=0;
        while(1){
            while(i<stations.size()){
                if(dist+fuel>=stations[i][0]){
                    pq.push({stations[i][1],stations[i][0]});
                    i++;
                }
                else{
                   break;
                }
            }
            dist+=fuel;
            fuel=0;
            if(dist>=target) break;
            if(pq.empty()){
                stops=-1;
                break;
            }
            auto top=pq.top();
            pq.pop();
            fuel=dist-top.second+top.first;
            dist=top.second;
            stops++;
        }
        return stops;
    }
};