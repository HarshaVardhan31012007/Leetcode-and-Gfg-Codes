// class Solution {
// public:
//     int solve(int i,int p,int n,vector<int> adjList [],vector<bool>&hasApple){
//         int ans=0;
//         for(auto &adj:adjList[i]){
//             if(adj!=p){
//                 ans+=solve(adj,i,n,adjList,hasApple);
//             }
//         }
//         if(p!=-1&&(hasApple[i]||ans>0)) ans+=2;
//         return ans;
//     }
//     int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
//         vector<int>adjList[n];
//         for(auto &each:edges){
//             adjList[each[0]].push_back(each[1]);
//             adjList[each[1]].push_back(each[0]);
//         }
//         return solve(0,-1,n,adjList,hasApple);
//     }
// };


class Solution {
public:
    int solve(int i,int p,int n,vector<int> adjList [],vector<bool>&hasApple){
        int ans=0;
        for(auto &adj:adjList[i]){
            if(adj!=p){
                int child=solve(adj,i,n,adjList,hasApple);
                if(hasApple[adj]||child>0)
                ans+=2;
                ans+=child;
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adjList[n];
        for(auto &each:edges){
            adjList[each[0]].push_back(each[1]);
            adjList[each[1]].push_back(each[0]);
        }
        return solve(0,-1,n,adjList,hasApple);
    }
};