class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // unordered_map<int,vector<pair<int,int>>>adjList;
        // for(auto &meeting:meetings){
        //     adjList[meeting[0]].push_back({meeting[1],meeting[2]});
        //     adjList[meeting[1]].push_back({meeting[0],meeting[2]});
        // }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        // pq.push({0,0});
        // pq.push({0,firstPerson});
        // vector<int>ans;
        // vector<int>time(n,INT_MAX);
        // time[0]=0;
        // time[firstPerson]=0;
        // while(!pq.empty()){
        //     auto top=pq.top();
        //     pq.pop();
        //     for(auto &adj:adjList[top.second]){
        //         if(top.first<=adj.second&&adj.second<time[adj.first]){
        //             time[adj.first]=adj.second;
        //             pq.push({time[adj.first],adj.first});
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(time[i]!=INT_MAX)
        //     ans.push_back(i);
        // }
        // return ans;



    //     vector<vector<pair<int,int>>>adjList(n);
    //     for(auto &meeting:meetings){
    //         adjList[meeting[0]].push_back({meeting[1],meeting[2]});
    //         adjList[meeting[1]].push_back({meeting[0],meeting[2]});
    //     }
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    //     pq.push({0,0});
    //     pq.push({0,firstPerson});
    //     vector<int>ans;
    //     vector<int>time(n,INT_MAX);
    //     time[0]=0;
    //     time[firstPerson]=0;
    //     while(!pq.empty()){
    //         auto top=pq.top();
    //         pq.pop();
    //         if (top.first > time[top.second]) continue;
    //         for(auto &adj:adjList[top.second]){
    //             if(top.first<=adj.second&&adj.second<time[adj.first]){
    //                 time[adj.first]=adj.second;
    //                 pq.push({time[adj.first],adj.first});
    //             }
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         if(time[i]!=INT_MAX)
    //         ans.push_back(i);
    //     }
    //     return ans;
    // }




     vector<vector<pair<int,int>>>adjList(n);
        for(auto &meeting:meetings){
            adjList[meeting[0]].push_back({meeting[1],meeting[2]});
            adjList[meeting[1]].push_back({meeting[0],meeting[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        vector<int>ans;
        vector<int>time(n,INT_MAX);
        time[0]=0;
        time[firstPerson]=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if (top.first > time[top.second]) continue;
            for(auto &adj:adjList[top.second]){
                if(top.first<=adj.second&&adj.second<time[adj.first]){
                    time[adj.first]=adj.second;
                    pq.push({time[adj.first],adj.first});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(time[i]!=INT_MAX)
            ans.push_back(i);
        }
        return ans;
    }
};