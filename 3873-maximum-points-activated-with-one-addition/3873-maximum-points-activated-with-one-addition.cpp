// class Solution {
// public:
//     int dfs(int x,int y,vector<vector<int>>&points,set<pair<int,int>>&visited){
//         visited.insert({x,y});
//         int count=1;
//         for(auto &each:points){
//             int a=each[0];
//             int b=each[1];
//             if(a==x||b==y){
//                 if(!visited.count({a,b})){
//                     count+=dfs(a,b,points,visited);
//                 }
//             }
//         }
//         return count;
//     }
//     int maxActivated(vector<vector<int>>& points) {
//        set<pair<int,int>>visited;
//        int size1=INT_MIN;int size2=INT_MIN;
//        for(int i=0;i<points.size();i++){
//             int ans=0;
//             if(!visited.count({points[i][0],points[i][1]})){
//                 ans=dfs(points[i][0],points[i][1],points,visited);
//             }
//             else continue;
//             if(size1<ans){
//                 size2=size1;
//                 size1=ans;
//             }
//             else if(size2<ans){
//                 size2=ans;
//             }
//        }
//        if(size1==INT_MIN) size1=0;
//        if(size2==INT_MIN) size2=0;
//        return size1+size2+1;
//     }
// };



class Solution {
public:
    class DSU{
        public:
        vector<int>parent,rank;
        
        DSU(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++)
            parent[i]=i;
        }
        
        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }
        
        void Union(int node1,int node2){
            int u=find(node1);
            int v=find(node2);
            if(u==v) return;
            if(rank[u]<rank[v]){
                parent[u]=v;
            }
            else if(rank[u]>rank[v]){
                parent[v]=u;
            }
            else{
                parent[v]=u;
                rank[u]++;
            }
        }
    };
    int maxActivated(vector<vector<int>>& points) {
        map<pair<int,int>,int>pMap;
        int mark=0;
        for(auto &each:points)
        pMap[{each[0],each[1]}]=mark++;
        DSU dsu(mark);
        unordered_map<int,int>xMap;
        unordered_map<int,int>yMap;
        for(auto &each:points){
            int x=each[0];
            int y=each[1];
            if(!xMap.count(x)){
                xMap[x]=pMap[{x,y}];
            }
            else
            dsu.Union(pMap[{x,y}],xMap[x]);
            if(!yMap.count(y)){
                yMap[y]=pMap[{x,y}];
            }
            else
            dsu.Union(pMap[{x,y}],yMap[y]);
        }

        for(auto &each:points){
            int x=each[0];
            int y=each[1];
            dsu.Union(xMap[x],yMap[y]);
        }
        
        map<int,int>mpp;
        for(auto &each:points){
            int v=dsu.find(pMap[{each[0],each[1]}]);
            mpp[v]++;
        }
        
        int maxi=INT_MIN;int secondMaxi=INT_MIN;
        for(auto &each:mpp){
            if(each.second>=maxi){
                secondMaxi=maxi;
                maxi=each.second;
            }
            else if(each.second>=secondMaxi){
                secondMaxi=each.second;
            }
        }
        if(maxi==INT_MIN) maxi=0;
        if(secondMaxi==INT_MIN) secondMaxi=0;
        return maxi+secondMaxi+1;
    }
};