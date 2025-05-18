class Solution {
public:
    #define INF (1e9+1)
    map<pair<int,int>,int>dp;
    int solve(vector<int>& arr1, vector<int>& arr2,int prev,int i){
        if(i>=arr1.size()) return 0;
        if(dp.find({prev,i})!=dp.end()) return dp[{prev,i}];
        int op1=INF;
        if(prev<arr1[i]){
            op1=solve(arr1,arr2,arr1[i],i+1);
        }
        int op2=INF;
        auto it=upper_bound(arr2.begin(),arr2.end(),prev);
        if(it!=arr2.end()){
            int idx=it-arr2.begin();
            op2=1+solve(arr1,arr2,arr2[idx],i+1);
        }
        return dp[{prev,i}]=min(op1,op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int ans=solve(arr1,arr2,-1,0);
        return (ans==INF)?-1:ans;
    }
};