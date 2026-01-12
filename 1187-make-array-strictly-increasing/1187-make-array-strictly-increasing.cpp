class Solution {
public:
    map<tuple<int,int>,int>mpp;
    int solve(vector<int>&arr1,vector<int>&arr2,int prev,int i){
        if(i>=arr1.size()) return 0;
        if(mpp.count({prev,i})) return mpp[{prev,i}];
        int ans=1e9;
        if(prev==-1||prev<arr1[i])
        ans=solve(arr1,arr2,arr1[i],i+1);
        auto idx=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(idx<arr2.size())
        ans=min(ans,1+solve(arr1,arr2,arr2[idx],i+1));
        return mpp[{prev,i}]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size()==1) return 0;
        sort(arr2.begin(),arr2.end());
        auto ans=solve(arr1,arr2,-1,0);
        return (ans==1e9)?-1:ans;
    }
};