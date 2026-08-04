class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // int n=routes.size();
        // unordered_map<int,vector<int>>mpp;
        // for(int i=0;i<n;i++){
        //     for(auto &each:routes[i]){
        //         mpp[each].push_back(i);
        //     }
        // }
        // queue<int>q;
        // q.push(source);
        // unordered_set<int>visitedStops;
        // visitedStops.insert(source);
        // int buses=0;
        // while(!q.empty()){
        //     int size=q.size();
        //     while(size--){
        //         int stop=q.front();
        //         q.pop();
        //         if(stop==target) return buses;
        //         for(auto &bus:mpp[stop]){
        //             for(auto &stops:routes[bus]){
        //                 if(visitedStops.count(stops)) continue;
        //                 q.push(stops);
        //                 visitedStops.insert(stops);
        //             }
        //         }
        //     }
        //     buses++;
        // }
        // return -1;



        // int n=routes.size();
        // unordered_map<int,vector<int>>mpp;
        // for(int i=0;i<n;i++){
        //     for(auto &each:routes[i]){
        //         mpp[each].push_back(i);
        //     }
        // }
        // queue<int>q;
        // q.push(source);
        // unordered_set<int>visitedStops;
        // vector<int>visitedBuses(n,0);
        // visitedStops.insert(source);
        // int buses=0;
        // while(!q.empty()){
        //     int size=q.size();
        //     while(size--){
        //         int stop=q.front();
        //         q.pop();
        //         if(stop==target) return buses;
        //         for(auto &bus:mpp[stop]){
        //             if(visitedBuses[bus]) continue;
        //             visitedBuses[bus]=1;
        //             for(auto &stops:routes[bus]){
        //                 if(visitedStops.count(stops)) continue;
        //                 q.push(stops);
        //                 visitedStops.insert(stops);
        //             }
        //         }
        //     }
        //     buses++;
        // }
        // return -1;



        int n=routes.size();
        unordered_map<int,vector<int>>mpp;
        queue<int>q;
        unordered_set<int>visitedStops;
        vector<int>visitedBuses(n,0);
        if(source==target) return 0;
        for(int i=0;i<n;i++){
            for(auto &each:routes[i]){
                mpp[each].push_back(i);
                if(each==source)
                q.push(i);
            }
        }
        int buses=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int bus=q.front();
                q.pop();
                for(auto &stop:routes[bus]){
                    if(stop==target) return buses;
                    for(auto &b:mpp[stop]){
                        if(visitedBuses[b]) continue;
                        visitedBuses[b]=1;
                        q.push(b);
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};