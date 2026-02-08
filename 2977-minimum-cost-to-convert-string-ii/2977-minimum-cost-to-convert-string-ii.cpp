class Solution {
public:
    // long long minimumCost(string source, string target,
    //                       vector<string>& original,
    //                       vector<string>& changed,
    //                       vector<int>& cost) {

    //     unordered_map<string, unordered_map<string, int>> mpp;
    //     unordered_set<string> st;

    //     for (int i = 0; i < original.size(); i++) {
    //         if (mpp.count(original[i]) &&
    //             mpp[original[i]].count(changed[i])) {

    //             mpp[original[i]][changed[i]] =
    //                 min(mpp[original[i]][changed[i]], cost[i]);
    //         } else {
    //             mpp[original[i]][changed[i]] = cost[i];
    //         }

    //         mpp[original[i]][original[i]] = 0;
    //         mpp[changed[i]][changed[i]] = 0;

    //         st.insert(original[i]);
    //         st.insert(changed[i]);
    //     }

    //     for (auto it = st.begin(); it != st.end(); it++) {
    //         for (auto it1 = st.begin(); it1 != st.end(); it1++) {
    //             for (auto it2 = st.begin(); it2 != st.end(); it2++) {

    //                 if (mpp.count(*it1) &&
    //                     mpp.count(*it) &&
    //                     mpp[*it1].count(*it) &&
    //                     mpp[*it].count(*it2)) {

    //                     if (mpp[*it1].count(*it2)) {
    //                         mpp[*it1][*it2] = min(
    //                             mpp[*it1][*it2],
    //                             mpp[*it1][*it] + mpp[*it][*it2]
    //                         );
    //                     } else {
    //                         mpp[*it1][*it2] =
    //                             mpp[*it1][*it] + mpp[*it][*it2];
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     int n = source.length();
    //     vector<int> dp(n + 1, INT_MAX);

    //     for (int i = 0; i < n; i++) {
    //         int j = i;
    //         string prev1 = "";
    //         string prev2 = "";

    //         while (j >= 0) {
    //             string s = source[j] + prev1;
    //             string t = target[j] + prev2;

    //             if ((j == 0 || dp[j - 1] != INT_MAX) &&
    //                 mpp.count(s) &&
    //                 mpp[s].count(t)) {

    //                 if (j > 0) {
    //                     dp[i] = min(dp[i],
    //                                 mpp[s][t] + dp[j - 1]);
    //                 } else {
    //                     dp[i] = mpp[s][t];
    //                 }
    //             }

    //             if (s == t) {
    //                 if (j > 0) {
    //                     dp[i] = min(dp[i], dp[j - 1]);
    //                 } else {
    //                     dp[i] = 0;
    //                 }
    //             }

    //             j--;

    //             prev1 = s;
    //             prev2 = t;
    //         }
    //     }

    //     return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
    // }



   long long minimumCost(string source, string target,
                      vector<string>& original,
                      vector<string>& changed,
                      vector<int>& cost) {

    const long long INF = 1e18;

    // ---- map strings to ids ----
    unordered_map<string,int> id;
    int idx = 0;
    for(int i=0;i<original.size();i++){
        if(!id.count(original[i])) id[original[i]] = idx++;
        if(!id.count(changed[i]))  id[changed[i]]  = idx++;
    }

    int m = idx;

    // ---- distance matrix ----
    vector<vector<long long>> dist(m, vector<long long>(m, INF));
    for(int i=0;i<m;i++) dist[i][i]=0;

    for(int i=0;i<original.size();i++){
        int u = id[original[i]];
        int v = id[changed[i]];
        dist[u][v] = min(dist[u][v], (long long)cost[i]);
    }

    // ---- Floyd Warshall ----
    for(int k=0;k<m;k++)
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                if(dist[i][k]<INF && dist[k][j]<INF)
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k]+dist[k][j]);

    // ---- collect rule lengths ----
    unordered_set<int> lens;
    for(auto &s: original) lens.insert(s.size());

    int n = source.size();
    vector<long long> dp(n+1, INF);
    dp[0] = 0;

    // ---- prefix DP ----
    for(int i=1;i<=n;i++){

        // case: keep single char unchanged
        if(source[i-1]==target[i-1] && dp[i-1]<INF)
            dp[i] = dp[i-1];

        // try rule lengths
        for(int len: lens){
            if(len > i) continue;

            int j = i-len;
            if(dp[j]==INF) continue;

            string s1 = source.substr(j,len);
            string t1 = target.substr(j,len);

            if(s1 == t1){
                dp[i] = min(dp[i], dp[j]);
                continue;
            }

            if(id.count(s1) && id.count(t1)){
                long long c = dist[id[s1]][id[t1]];
                if(c < INF)
                    dp[i] = min(dp[i], dp[j] + c);
            }
        }
    }

    return dp[n]==INF ? -1 : dp[n];
}


};
