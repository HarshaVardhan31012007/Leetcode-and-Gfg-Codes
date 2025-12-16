// class Solution {
// public:
//     int solve(int i,vector<int>&present,vector<int>&future,int n,int budget,bool flag,unordered_map<int,list<int>>&adjList){
//         if(flag){
//             int one=0;
//             if((budget-(present[i]/2))>=0){
//                 one=(future[i]-(present[i]/2));
//                 for(auto &adj:adjList[i])
//                 one+=solve(adj,present,future,n,budget-(present[i]/2),true,adjList);
//             }
//             int two=0;
//             for(auto &adj:adjList[i])
//             two+=solve(adj,present,future,n,budget,false,adjList);
//             return max(one,two);
//         }
//         else{
//             int one=0;
//             if((budget-present[i])>=0){
//                 one=(future[i]-present[i]);
//                 for(auto &adj:adjList[i])
//                 one+=solve(adj,present,future,n,budget-present[i],true,adjList);
//             }
//             int two=0;
//             for(auto &adj:adjList[i])
//             two+=solve(adj,present,future,n,budget,false,adjList);
//             return max(one,two);
//         }
//     }
//     int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
//         unordered_map<int,list<int>>adjList;
//         for(auto &each:hierarchy){
//             adjList[each[0]-1].push_back(each[1]-1);
//         }
//         return solve(0,present,future,n,budget,false,adjList);
//     }
// };




class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> g(n);

        for (auto& e : hierarchy) {
            g[e[0] - 1].push_back(e[1] - 1);
        }

        auto dfs = [&](auto&& self,
                       int u) -> tuple<vector<int>, vector<int>, int> {
            int cost = present[u];
            int dCost = present[u] / 2;  // discounted cost

            // dp[u][state][budget]
            // state = 0: Do not purchase parent node, state = 1: Must purchase
            // parent node
            auto dp0 = vector(budget + 1, 0);
            auto dp1 = vector(budget + 1, 0);

            // subProfit[state][budget]
            // state = 0: discount not available, state = 1: discount available
            auto subProfit0 = vector(budget + 1, 0);
            auto subProfit1 = vector(budget + 1, 0);

            int uSize = cost;

            for (auto v : g[u]) {
                auto [subDp0, subDp1, vSize] = self(self, v);
                uSize += vSize;
                for (int i = budget; i >= 0; i--) {
                    for (int sub = 0; sub <= min(vSize, i); sub++) {
                        subProfit0[i] = max(subProfit0[i],
                                            subProfit0[i - sub] + subDp0[sub]);
                        subProfit1[i] = max(subProfit1[i],
                                            subProfit1[i - sub] + subDp1[sub]);
                    }
                }
            }

            for (int i = 0; i <= budget; i++) {
                dp0[i] = dp1[i] = subProfit0[i];

                if (i >= dCost) {
                    dp1[i] = max(subProfit0[i],
                                 subProfit1[i - dCost] + future[u] - dCost);
                }

                if (i >= cost) {
                    dp0[i] = max(subProfit0[i],
                                 subProfit1[i - cost] + future[u] - cost);
                }
            }

            return {dp0, dp1, uSize};
        };

        return std::get<0>(dfs(dfs, 0))[budget];
    }
};