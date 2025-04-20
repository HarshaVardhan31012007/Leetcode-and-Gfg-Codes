class Solution {
public:
    void dijkstrasalgo(unordered_map<int,list<pair<int,long long int>>>&adjList,vector<long long int>&distance,vector<int>&parent,vector<int>&ways,int src){
        set<pair<long long int,int>>st;
        distance[src]=0;
        parent[src]=-1;
        st.insert({0,0});
        int a=(1e9+7);
        while(!st.empty()){
            auto front=*st.begin();
            st.erase(st.begin());
            for(auto &nbr:adjList[front.second]){
                if(distance[front.second]+nbr.second<distance[nbr.first]){
                    auto it=st.find({distance[nbr.first],nbr.first});
                    if(it!=st.end())
                    st.erase(it);
                    ways[nbr.first]=ways[front.second];
                    distance[nbr.first]=distance[front.second]+nbr.second;
                    parent[nbr.first]=front.second;
                    st.insert({distance[nbr.first],nbr.first});
                }
                else if(distance[front.second]+nbr.second==distance[nbr.first]){
                   ways[nbr.first]=(ways[nbr.first]+ways[front.second]) % a;
                }
            }
        }
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,list<pair<int,long long int>>>adjList;
        for(int i=0;i<roads.size();i++){
            adjList[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adjList[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long int>distance(n,LLONG_MAX);
        vector<int>parent(n);
        vector<int>ways(n,0);
        int src=0;
        ways[src]=1;
        dijkstrasalgo(adjList,distance,parent,ways,src);
        return ways[n-1];
    }
};