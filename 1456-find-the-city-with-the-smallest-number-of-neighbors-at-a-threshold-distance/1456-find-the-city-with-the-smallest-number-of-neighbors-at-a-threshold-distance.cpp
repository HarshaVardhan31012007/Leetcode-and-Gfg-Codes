class Solution {
public:
    void dijkstrasalgo(unordered_map<int,list<pair<int,int>>>&adjList,int d,int s,int n,int &count){
        set<pair<int,int>>st;
        st.insert({0,s});
        vector<int>distance(n,INT_MAX);
        distance[s]=0;
        while(!st.empty()){
            auto front=*st.begin();
            st.erase(st.begin());
            if(front.second!=s&&front.first<=d){
                count++;
            }
            for(auto &nbr:adjList[front.second]){
                 if(distance[front.second]+nbr.second<distance[nbr.first]){
                    if(st.find({distance[nbr.first],nbr.first})!=st.end()){
                        st.erase({distance[nbr.first],nbr.first});
                    }
                    distance[nbr.first]=distance[front.second]+nbr.second;
                    st.insert({distance[nbr.first],nbr.first});
                 }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>>adjList;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        int ans=INT_MAX;int city=-1;
        for(int i=0;i<n;i++){
           int count=0;
           dijkstrasalgo(adjList,distanceThreshold,i,n,count);
           ans=min(ans,count);
           if(ans==count)
           city=i;
        }
        return city;
    }
};