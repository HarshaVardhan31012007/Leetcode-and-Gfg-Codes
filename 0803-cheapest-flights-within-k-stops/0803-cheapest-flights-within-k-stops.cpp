class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {    
    //    unordered_map<int,list<pair<int,int>>>adjList;
    //    for(auto &flight:flights){
    //     adjList[flight[0]].push_back({flight[1],flight[2]});
    //    }
    //    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    //    vector<int>visited(n,INT_MAX);
    //    visited[src]=0;
    //    pq.push({0,src,0});
    //    while(!pq.empty()){
    //     auto front=pq.top();
    //     pq.pop();
    //     if(front[1]==dst) return front[0];
    //     if(front[2]>k) continue;
    //     if(visited[front[1]]<front[2]) continue;
    //     visited[front[1]]=min(visited[front[1]],front[2]);
    //     for(auto &nbr:adjList[front[1]]){
    //         pq.push({front[0]+nbr.second,nbr.first,front[2]+1});
    //     }
    //    }
    //    return -1;



    // vector<int>distance(n,1e9);
    // distance[src]=0;
    // queue<vector<int>>q;
    // q.push({0,src,0});
    // while(!q.empty()){
    //     auto front=q.front();
    //     q.pop();
        // if(front[0]>k) continue;
        // for(auto &nbr:adjList[front[1]]){
        //     if(front[2]+nbr.second<distance[nbr.first]&&front[0]<=k){
        //             distance[nbr.first]=front[2]+nbr.second;
        //             q.push({front[0]+1,nbr.first,distance[nbr.first]});
        //     }
        // }

    //      if(front[0]<=k){
    //     for(auto &nbr:adjList[front[1]]){
    //         if(front[2]+nbr.second<distance[nbr.first]){
    //                 distance[nbr.first]=front[2]+nbr.second;
    //                 q.push({front[0]+1,nbr.first,distance[nbr.first]});
    //         }
    //      }
    //      }
    // }
    //    return (distance[dst]==1e9)?-1:distance[dst];





    //BELLMANFORD ALGORITHM

    vector<int>distance(n,INT_MAX);
    distance[src]=0;
    for(int i=0;i<k+1;i++){
        vector<int>temp(distance);
        for(auto &flight:flights){
            if(distance[flight[0]]!=INT_MAX){
                temp[flight[1]]=min(temp[flight[1]],distance[flight[0]]+flight[2]);
            }
        }
        distance=temp;
    }
    return (distance[dst]==INT_MAX)?-1:distance[dst];
    }
};