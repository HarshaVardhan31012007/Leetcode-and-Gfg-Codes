class Solution {
public:
    //incorrect as adjacent nodes depends on each other for budget//more cases 2 powern take not take
   
    // int solve(int i,vector<int>&present,vector<int>&future,int n,int budget,bool flag,unordered_map<int,list<int>>&adjList){
    //     if(flag){
    //         int one=0;
    //         if((budget-(present[i]/2))>=0){
    //             one=(future[i]-(present[i]/2));
    //             for(auto &adj:adjList[i])
    //             one+=solve(adj,present,future,n,budget-(present[i]/2),true,adjList);
    //         }
    //         int two=0;
    //         for(auto &adj:adjList[i])
    //         two+=solve(adj,present,future,n,budget,false,adjList);
    //         return max(one,two);
    //     }
    //     else{
    //         int one=0;
    //         if((budget-present[i])>=0){
    //             one=(future[i]-present[i]);
    //             for(auto &adj:adjList[i])
    //             one+=solve(adj,present,future,n,budget-present[i],true,adjList);
    //         }
    //         int two=0;
    //         for(auto &adj:adjList[i])
    //         two+=solve(adj,present,future,n,budget,false,adjList);
    //         return max(one,two);
    //     }
    // }
    // int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
    //     unordered_map<int,list<int>>adjList;
    //     for(auto &each:hierarchy){
    //         adjList[each[0]-1].push_back(each[1]-1);
    //     }
    //     return solve(0,present,future,n,budget,false,adjList);
    // }


    // int solve(int i,vector<int>&parent,vector<bool>&purchase,vector<int>&topo,int budget,vector<int>&present,vector<int>&future){
    //      if(budget<0) return -1e9;//to avoid overflows if some neg+INT_MIN out of integer
    //      if(i==topo.size()) return 0;
    //      int price=present[topo[i]];
    //      int boss=parent[topo[i]];
    //      if(boss!=-1&&purchase[boss]){
    //          price=price/2;
    //      }
    //      purchase[topo[i]]=1;
    //      int inc=future[topo[i]]-price+solve(i+1,parent,purchase,topo,budget-price,present,future);
    //      purchase[topo[i]]=0;
    //      int exc=solve(i+1,parent,purchase,topo,budget,present,future);
    //      return max(inc,exc);
    // }
    // int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
    //     unordered_map<int,list<int>>adjList;
    //     vector<int>parent(n,-1);
    //     vector<int>indegree(n);
    //     for(auto &each:hierarchy){
    //         adjList[each[0]-1].push_back(each[1]-1);
    //         parent[each[1]-1]=each[0]-1;
    //         indegree[each[1]-1]++;
    //     }
    //     vector<int>topo;
    //     queue<int>q;
    //     q.push(0);
    //     while(!q.empty()){
    //          auto front=q.front();
    //          q.pop();
    //          topo.push_back(front);
    //          for(auto &adj:adjList[front]){
    //              indegree[adj]--;
    //              if(indegree[adj]==0){
    //                 q.push(adj);
    //              }
    //          }
    //     }
    //     vector<bool>purchase(n,0);
    //     return solve(0,parent,purchase,topo,budget,present,future);
    // }



     void dfs(int i,int n,unordered_map<int,list<int>>&adjList,vector<int>&present,vector<int>&future,int budget,vector<vector<vector<int>>>&dp){
        vector<pair<vector<int>,vector<int>>>childDPs;

        for(auto &c:adjList[i]){
            dfs(c,n,adjList,present,future,budget,dp);
            childDPs.push_back({dp[c][0],dp[c][1]});
        }

        for(int parent=0;parent<=1;parent++){
           int price=(parent==1)?present[i]/2:present[i];
           int profit=future[i]-price;
           vector<int>best(budget+1,0);
           vector<int>one(budget+1,0);
           //case 1//current node not buy
           for(auto &child:childDPs){
               vector<int>temp(budget+1,0);
               for(int used=0;used<=budget;used++){
                   for(int take=0;used+take<=budget;take++){
                        temp[used+take]=max(temp[used+take],one[used]+child.first[take]);
                   }
               }
               one=move(temp);
           }
           for(int i=0;i<=budget;i++){
              best[i]=max(best[i],one[i]);
           }
           //case 2//currnode buy
           if(price<=budget){
                vector<int>two(budget+1,0);
                for(auto &child:childDPs){
                    vector<int>temp(budget+1,0);
                    for(int used=0;used<=budget;used++){
                        for(int take=0;used+take<=budget;take++){
                                temp[used+take]=max(temp[used+take],two[used]+child.second[take]);
                        }
                    }
                    two=move(temp);
                }
                for(int i=price;i<=budget;i++){
                    best[i]=max(best[i],profit+two[i-price]);
                }
           }
           dp[i][parent]=best;
        }
     }
     int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
       unordered_map<int,list<int>>adjList;
       for(auto &each:hierarchy){
            adjList[each[0]-1].push_back(each[1]-1);
       }
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(budget+1,0)));
       dfs(0,n,adjList,present,future,budget,dp);
       int ans=0;
       for(int i=0;i<=budget;i++){
           ans=max(ans,dp[0][0][i]);
       }
       return ans;
    }

};