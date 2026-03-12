// class Solution {
// public:
//     int findParent(int u,vector<int>&parent){
//         if(parent[u]==u) return u;
//         return parent[u]=findParent(parent[u],parent);
//     }
//     void unionHelp(int u,int v,vector<int>&parent,vector<int>&rank){
//         if(rank[u]<rank[v]){
//             parent[u]=v;
//             rank[v]++;
//         }
//         else{
//             parent[v]=u;
//             rank[u]++;
//         }
//     }
//     int maxStability(int n, vector<vector<int>>& edges, int k) {
//         int minEdges=n-1;
//         int nedges=edges.size();
//         if(minEdges>nedges) return -1;
//         vector<int>parent(n,-1);
//         for(int i=0;i<n;i++)
//         parent[i]=i;
//         vector<int>rank(n,0);
//         priority_queue<pair<int,pair<int,int>>>pq;
//         int c=0;
//         int mini=INT_MAX;
//         for(auto &edge:edges){
//             int u=edge[0];int v=edge[1];int s=edge[2];
//             int must=edge[3];
//             if(must){
//                int node1=findParent(u,parent);int node2=findParent(v,parent);
//                if(node1==node2) return -1;
//                else unionHelp(node1,node2,parent,rank);
//                if(s<mini){
//                     mini=s;
//                 }
//                 c++;
//             }
//             else{
//                pq.push({s,{u,v}});
//             }
//         }
//         vector<int>v;
//         while(!pq.empty()){
//             auto front=pq.top();
//             int u=front.second.first;int v1=front.second.second;
//             int s1=front.first;
//             pq.pop();
//             int node1=findParent(u,parent);int node2=findParent(v1,parent);
//             if(node1==node2) continue;
//             unionHelp(node1,node2,parent,rank);
//             v.push_back(s1);
//             c++;
//         }
//         if(c!=n-1) return -1;
//         sort(v.begin(),v.end());
//         if(v.empty()) return mini;
//         for(int i=0;i<k&&i<v.size();i++)
//         v[i]=(v[i]*2);
//         int mini1=*min_element(v.begin(),v.end());
//         return min(mini,mini1);
//     }
// };



class Solution {
public:
    int findParent(int u,vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]=findParent(parent[u],parent);
    }
    void unionHelp(int u,int v,vector<int>&parent,vector<int>&rank){
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int minEdges=n-1;
        int nedges=edges.size();
        if(minEdges>nedges) return -1;
        vector<int>parent(n,-1);
        for(int i=0;i<n;i++)
        parent[i]=i;
        vector<int>rank(n,0);
        priority_queue<pair<int,pair<int,int>>>pq;
        int c=0;
        int mini=INT_MAX;
        for(auto &edge:edges){
            int u=edge[0];int v=edge[1];int s=edge[2];
            int must=edge[3];
            if(must){
               int node1=findParent(u,parent);int node2=findParent(v,parent);
               if(node1==node2) return -1;//cycle
               else unionHelp(node1,node2,parent,rank);
               if(s<mini){
                    mini=s;
                }
                c++;
            }
            else{
               pq.push({s,{u,v}});
            }
        }
        int mini1=INT_MAX;
        priority_queue<int,vector<int>,greater<>>pq1;
        while(!pq.empty()){
            auto front=pq.top();
            int u=front.second.first;int v1=front.second.second;
            int s1=front.first;
            pq.pop();
            int node1=findParent(u,parent);int node2=findParent(v1,parent);
            if(node1==node2) continue;
            unionHelp(node1,node2,parent,rank);
            pq1.push(s1);
            c++;
        }
        while(!pq1.empty()&&k--){
            auto top=pq1.top();
            pq1.pop();
            mini1=min(mini1,2*top);
        }
        while(!pq1.empty()){
            mini1=min(mini1,pq1.top());
            pq1.pop();
        }
        if(c!=n-1) return -1;//disconnected graph
        return min(mini,mini1);
    }
};