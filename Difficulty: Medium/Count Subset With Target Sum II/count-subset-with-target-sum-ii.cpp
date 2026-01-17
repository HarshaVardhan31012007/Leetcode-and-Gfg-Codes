class Solution {
  public:
    //  int solve(vector<int>&arr,int i,int target,vector<unordered_map<int,int>>&dp){
    //     if(i>=arr.size()) return target==0;
    //     if(dp[i].count(target)!=-1) return dp[i][target];
    //     int inc=solve(arr,i+1,target-arr[i],dp);
    //     int exc=solve(arr,i+1,target,dp);
    //     return dp[i][target]=inc+exc;
    // }
    // int countSubset(vector<int> &arr, int k) {
    //     vector<unordered_map<int,int>>dp(arr.size()+1);
    //     return solve(arr,0,k,dp);
    // }
    

    int countSubset(vector<int> &arr, int k) {
        int n=arr.size();
        int mid=n/2;
        vector<int>left(arr.begin(),arr.begin()+mid);
        vector<int>right(arr.begin()+mid,arr.end());
        int m=left.size();n=right.size();
        vector<int>leftS,rightS;
        for(int mask=0;mask<(1<<m);mask++){
            int temp=mask;
            int i=0;int sum=0;
            while(temp){
                if(temp&1){
                    sum+=left[i];
                }
                temp=temp>>1;i++;
            }
            leftS.push_back(sum);
        }
        for(int mask=0;mask<(1<<n);mask++){
            int temp=mask;
            int i=0;int sum=0;
            while(temp){
                if(temp&1){
                    sum+=right[i];
                }
                temp=temp>>1;i++;
            }
            rightS.push_back(sum);
        }
        sort(rightS.begin(),rightS.end());
        int ans=0;
        for(auto &each:leftS){
            int need=k-each;
            int count=upper_bound(rightS.begin(),rightS.end(),need)-lower_bound(rightS.begin(),rightS.end(),need);
            ans+=count;
        }
        return ans;
    }
};