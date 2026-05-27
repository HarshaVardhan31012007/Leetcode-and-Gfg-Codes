class Solution {
public:

    //wrong approach

    // void fillprevG(vector<int>&arr,int n,vector<int>&prevG){
    //     stack<int>st;
    //     for(int i=0;i<n;i++){
    //         while(!st.empty()&&arr[st.top()]<arr[i]){
    //             st.pop();
    //         }
    //         if(!st.empty())
    //         prevG[i]=st.top();
    //         st.push(i);
    //     }
    // }
    // void fillnextG(vector<int>&arr,int n,vector<int>&nextG){
    //     stack<int>st;
    //     for(int i=n-1;i>=0;i--){
    //         while(!st.empty()&&arr[st.top()]<arr[i]){
    //             st.pop();
    //         }
    //         if(!st.empty())
    //         nextG[i]=st.top();
    //         st.push(i);
    //     }
    // }
    // int maxJumps(vector<int>& arr, int d) {
    //     int n=arr.size();
    //     vector<int>prevG(n,-1);
    //     vector<int>nextG(n,n);
    //     fillprevG(arr,n,prevG);
    //     fillnextG(arr,n,nextG);
    //     vector<int>dp1(n,1);
    //     for(int i=0;i<n;i++){
    //         for(int j=i-1;j>=max((i-d),prevG[i]+1);j--){
    //              dp1[i]=max(dp1[i],dp1[j]+1);
    //         }
    //     }
    //     vector<int>dp2(n,1);
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=i+1;j<=min((i+d),nextG[i]-1);j++){
    //              dp2[i]=max(dp2[i],dp2[j]+1);
    //         }
    //     }
    //     vector<int>dp(n,0);
    //     for(int i=0;i<n;i++){
    //        dp[i]=max(dp1[i],dp2[i]);
    //     }
    //     int ans=1;
    //     for(int i=0;i<n;i++){
    //         for(int j=max((i-d),prevG[i]+1);j<=min((i+d),nextG[i]-1);j++){
    //             dp[i]=max(dp[i],dp[j]+1);
    //         }
    //         ans=max(ans,dp[i]);
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=max((i-d),prevG[i]+1);j<=min((i+d),nextG[i]-1);j++){
    //             dp[i]=max(dp[i],dp[j]+1);
    //         }
    //         ans=max(ans,dp[i]);
    //     }
    //     return ans;
    // }



    int maxJumps(vector<int>& arr, int d) {
        vector<pair<int,int>>v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        int ans=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            int val=v[i].first;
            int idx=v[i].second;
            int maxi=1;
            for(int j=idx-1;j>=max((idx-d),0);j--){
                if(arr[j]>=arr[idx]) break;
                maxi=max(maxi,dp[j]+1);
            }
            for(int j=idx+1;j<=min((idx+d),n-1);j++){
                if(arr[j]>=arr[idx]) break;
                maxi=max(maxi,dp[j]+1);
            }
            dp[idx]=maxi;
            ans=max(ans,dp[idx]);
        }
        return ans;
    }
};