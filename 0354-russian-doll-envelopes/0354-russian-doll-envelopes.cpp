class Solution {
public:
    //DP 
    //TLE
    // bool issafe(vector<int>&c1,vector<int>&c2){
    //     if(c1[0]<c2[0] && c1[1]<c2[1])
    //     return true;
    //     else
    //     return false;
    // }
    // int solve(vector<vector<int>>& envelopes,int n){
    //     vector<int>cur(n+1,0);
    //     for(int curr=n-1;curr>=0;curr--){
    //             for(int prev=curr-1;prev>=-1;prev--){
    //             int l=0;
    //             if(prev==-1||issafe(envelopes[prev],envelopes[curr]))
    //             l=1+cur[curr+1];
    //             int r=cur[prev+1];
    //             cur[prev+1]=max(l,r);
    //         }
    //     }
    //     return cur[0];
    // }
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     int n=envelopes.size();
    //     sort(envelopes.begin(),envelopes.end());
    //     return solve(envelopes,n);
    // }
    
    // static bool comp(vector<int>&a,vector<int>&b){
    //     if(a[0]==b[0])
    //     return a[1]>b[1];
    //     else
    //     return a[0]<b[0];
    // }
    // int solve(vector<vector<int>>&envelopes,int n){
    //     vector<int>ans;
    //     ans.push_back(envelopes[0][1]);
    //     for(int i=1;i<envelopes.size();i++){
    //         if(envelopes[i][1]>ans.back()){
    //             ans.push_back(envelopes[i][1]);
    //         }
    //         else{
    //             int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
    //             ans[index]=envelopes[i][1];
    //         }
    //     }
    //     return ans.size();
    // }
    // int maxEnvelopes(vector<vector<int>>&envelopes){
    //     int n=envelopes.size();
    //     sort(envelopes.begin(),envelopes.end(),comp);
    //     return solve(envelopes,n);
    // }

   

   
    int maxEnvelopes(vector<vector<int>>&envelopes){
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                auto idx=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[idx]=envelopes[i][1];
            }
        }
        return ans.size();
    }
};