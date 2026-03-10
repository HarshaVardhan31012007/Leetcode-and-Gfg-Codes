class Solution {
public:
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     unordered_map<int,list<pair<int,int>>>adjList;
    //     for(auto &each:flights){
    //          int u=each[0];
    //          int v=each[1];
    //          int w=each[2];
    //          adjList[u].push_back({v,w});
    //     }
    //     vector<vector<int>>price(n,vector<int>(k+2,INT_MAX));
    //     price[src][k+1]=0;
    //     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
    //     pq.push({0,{src,k+1}});
    //     while(!pq.empty()){
    //         auto top=pq.top();
    //         int cprice=top.first;
    //         int city=top.second.first;
    //         int stops=top.second.second;
    //         pq.pop();
    //         if(city==dst) return cprice;
    //         for(auto &adj:adjList[city]){
    //             int v=adj.first;int w=adj.second;
    //             if(cprice+w<price[v][stops]&&stops>0){
    //                 price[v][stops]=cprice+w;
    //                 pq.push({price[v][stops],{v,stops-1}});
    //             }
    //         }
    //     }
    //     return -1;
    // }





    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>>adjList;
        for(auto &each:flights){
             int u=each[0];
             int v=each[1];
             int w=each[2];
             adjList[u].push_back({v,w});
        }
        vector<int>price(n,INT_MAX);
        price[src]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto top=pq.top();
            int cprice=top.second.second;
            int city=top.second.first;
            int stops=top.first;
            pq.pop();
            for(auto &adj:adjList[city]){
                int v=adj.first;int w=adj.second;
                if(cprice+w<price[v]&&stops<=k){
                    price[v]=cprice+w;
                    pq.push({stops+1,{v,price[v]}});
                }
            }
        }
        return price[dst]==INT_MAX?-1:price[dst];
    }
};