class Solution {
public:
    // void dfs(int person,int t,vector<vector<pair<int,int>>>&adjList,vector<int>&time){
    //         for(auto &adj:adjList[person]){
    //            if(adj.second>=t&&time[adj.first]>adj.second){
    //               time[adj.first]=adj.second;
    //               dfs(adj.first,adj.second,adjList,time);
    //            }
    //         }
    // }

    int find(int node,vector<int>&parent){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node],parent);
    }
    void unionHelp(int x,int y,vector<int>&parent,vector<int>&rank){
        int u=find(x,parent);
        int v=find(y,parent);
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        // map<int,vector<pair<int,int>>>mpp;
        // for(auto &meeting:meetings){
        //     mpp[meeting[2]].push_back({meeting[0],meeting[1]});
        // }
        // vector<bool>knowSecret(n,0);
        // knowSecret[0]=1;
        // knowSecret[firstPerson]=1;
        // for(auto &each:mpp){
        //     unordered_map<int,list<int>>adjList;
        //     queue<int>q;
        //     for(auto &[person1,person2]:each.second){
        //         adjList[person1].push_back(person2);
        //         adjList[person2].push_back(person1);
        //     }
        //     for(int i=0;i<n;i++){
        //         if(knowSecret[i])
        //         q.push(i);
        //     }
        //     while(!q.empty()){
        //         auto front=q.front();
        //         q.pop();
        //         for(auto &adj:adjList[front]){
        //             if(!knowSecret[adj]){
        //                 q.push(adj);
        //                 knowSecret[adj]=1;
        //             }
        //         }
        //     }
        // }
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(knowSecret[i])
        //     ans.push_back(i);
        // }
        // return ans;



        // vector<vector<pair<int,int>>>adjList(n);
        // for(auto &meeting:meetings){
        //     adjList[meeting[0]].push_back({meeting[1],meeting[2]});
        //     adjList[meeting[1]].push_back({meeting[0],meeting[2]});
        // }
        // vector<int>time(n,INT_MAX);
        // time[0]=0;
        // time[firstPerson]=0;
        // queue<pair<int,int>>q;
        // q.push({0,0});
        // q.push({firstPerson,0});
        // while(!q.empty()){
        //     auto [person,t]=q.front();
        //     q.pop();
        //     for(auto &adj:adjList[person]){
        //        if(adj.second>=t&&time[adj.first]>adj.second){
        //           time[adj.first]=adj.second;
        //           q.push({adj.first,adj.second});
        //        }
        //     }
        // }
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(time[i]!=INT_MAX)
        //     ans.push_back(i);
        // }
        // return ans;



        // vector<vector<pair<int,int>>>adjList(n);
        // for(auto &meeting:meetings){
        //     adjList[meeting[0]].push_back({meeting[1],meeting[2]});
        //     adjList[meeting[1]].push_back({meeting[0],meeting[2]});
        // }
        // vector<int>time(n,INT_MAX);
        // time[0]=0;
        // time[firstPerson]=0;
        // dfs(0,0,adjList,time);
        // dfs(firstPerson,0,adjList,time);
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(time[i]!=INT_MAX)
        //     ans.push_back(i);
        // }
        // return ans;




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



            // vector<vector<pair<int,int>>>adjList(n);
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
            //     if (top.first > time[top.second]) continue;
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



            vector<int>parent(n,0);
            vector<int>rank(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
            sort(meetings.begin(),meetings.end(),[&](vector<int>&a,vector<int>&b){
                 if(a[2]!=b[2])
                 return a[2]<b[2];
                 else if(a[1]!=b[1])
                 return a[1]<b[1];
                 else
                 return a[0]<b[0];
            });
            unionHelp(0,firstPerson,parent,rank);
            for(int i=0;i<meetings.size();){
                int time=meetings[i][2];
                vector<int>curr;
                while(i<meetings.size()&&time==meetings[i][2]){
                    unionHelp(meetings[i][0],meetings[i][1],parent,rank);
                    curr.push_back(meetings[i][0]);
                    curr.push_back(meetings[i][1]);
                    i++;
                }
                for(auto &each:curr){
                    if(parent[each]!=each&&find(each,parent)!=find(0,parent)){
                        parent[each]=each;//reset logic as meetings is ended and no connection to secret knowing people //ony two cases wither all connected to 0 or all not connected to 0
                    }
                }
            }
            vector<int>ans;
            for(int i=0;i<n;i++){
                if(find(i,parent)==find(0,parent)){
                    ans.push_back(i);
                }
            }
            return ans;
        }
};