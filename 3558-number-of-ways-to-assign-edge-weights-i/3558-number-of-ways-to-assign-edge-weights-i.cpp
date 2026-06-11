class Solution {
public:
    // int find(int node,int p,unordered_map<int,list<int>>&adjList){
    //     int ans=0;
    //     for(auto &adj:adjList[node]){
    //         if(adj!=p)
    //         ans=max(ans,1+find(adj,node,adjList));
    //     }
    //     return ans;
    // }
    // const int mod=1000000007;
    // int assignEdgeWeights(vector<vector<int>>& edges) {
    //     unordered_map<int,list<int>>adjList;
    //     for(auto &each:edges){
    //         adjList[each[0]].push_back(each[1]);
    //         adjList[each[1]].push_back(each[0]);
    //     }
    //     int maxDepth=find(1,-1,adjList);
    //     vector<long long>factorial(maxDepth+1);
    //     factorial[0LL]=1;
    //     for(long long i=1;i<=maxDepth;i++){
    //         factorial[i]=(factorial[i-1]*1LL*i)%mod;
    //     }
    //     long long ans=0;
    //     for(int i=1;i<=maxDepth;i+=2){
    //         long long x=factorial[i];
    //         long long y=factorial[maxDepth-i];
    //         long long curr=(factorial[maxDepth]/(x*y));
    //         ans=(ans+curr)%mod;
    //     }
    //     return ans%mod;
    // }


    
    int find(int node,int p,unordered_map<int,list<int>>&adjList){
        int ans=0;
        for(auto &adj:adjList[node]){
            if(adj!=p)
            ans=max(ans,1+find(adj,node,adjList));
        }
        return ans;
    }
    const int mod=1000000007;
    int power(int a,int b){
        long long res=1;
        while(b!=0){
            if(b&1){
                res=(res*a)%mod;
            }
            a=(1LL*a*a)%mod;
            b=b>>1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adjList;
        for(auto &each:edges){
            adjList[each[0]].push_back(each[1]);
            adjList[each[1]].push_back(each[0]);
        }
        int maxDepth=find(1,-1,adjList);
        return power(2,maxDepth-1);
    }
};