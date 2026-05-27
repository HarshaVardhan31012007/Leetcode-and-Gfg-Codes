class Solution {
public:
    //dfs

    //  bool dfs(int i,int maxi,string &s,int &n,int &minJump,int &maxJump,vector<int>&visited){
    //     visited[i]=1;
    //     if(i==(n-1)) return true;
    //     int end=i+maxJump;
    //     int start=(i+minJump);
    //     if(start<=maxi) start=maxi+1;
    //     int maxi1=min(end,n-1);
    //     for(int j=start;j<=min(end,n-1);j++){
    //         if(visited[j]==0&&s[j]=='0'){
    //             bool ans=dfs(j,maxi1,s,n,minJump,maxJump,visited);
    //             if(ans) return true;
    //             maxi1=max(maxi1,min(j+maxJump,n-1));
    //         }
    //     }
    //     return false;
    // }
    // bool canReach(string s, int minJump, int maxJump) {
    //     int n=s.length();
    //     if(s[n-1]=='1') return false;
    //     vector<int>visited(n,0);
    //     return dfs(0,0,s,n,minJump,maxJump,visited);
    // }


    //bfs
    // bool canReach(string s, int minJump, int maxJump) {
    //     // int n=s.length();
    //     // if(s[n-1]=='1') return false;
    //     // vector<int>visited(n,0);
    //     // queue<int>q;
    //     // q.push(0);
    //     // visited[0]=1;
    //     // int maxi=0;
    //     // while(!q.empty()){
    //     //     int idx=q.front();
    //     //     q.pop();
    //     //     if(idx==(n-1)) return true;
    //     //     for(int j=max(maxi+1,idx+minJump);j<=min(idx+maxJump,n-1);j++){
    //     //         maxi=max(maxi,j);
    //     //         if(visited[j]==0&&s[j]=='0'){
    //     //             q.push(j);
    //     //             visited[j]=1;
    //     //         }
    //     //     }
    //     // }
    //     // return false;
    // }


    // bool solve(int i,string &s,int &n,int &minJump,int &maxJump,vector<int>&dp){
    //     if(i==(n-1)) return true;
    //     if(dp[i]!=-1) return dp[i];
    //     bool ans=false;
    //     for(int j=(i+minJump);j<=min(i+maxJump,n-1);j++){
    //         if(s[j]=='0')
    //         ans=ans||solve(j,s,n,minJump,maxJump,dp);
    //     }
    //     return dp[i]=ans;
    // }
    // bool canReach(string s, int minJump, int maxJump) {
    //     int n=s.length();
    //     vector<int>dp(n,-1);
    //     return solve(0,s,n,minJump,maxJump,dp);
    // }



    
    // bool canReach(string s, int minJump, int maxJump) {
    //     int n=s.length();
    //     vector<int>dp(n,0);
    //     dp[n-1]=1;
    //     for(int i=(n-2);i>=0;i--){
    //         bool ans=false;
    //         for(int j=(i+minJump);j<=min(i+maxJump,n-1);j++){
    //             if(s[j]=='0')
    //             ans=ans||dp[j];
    //         }
    //         dp[i]=ans;
    //     }
    //     return dp[0]==1;
    // }



    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        vector<int>dp(n,0);
        dp[n-1]=1;
        int count=0;
        for(int i=(n-2);i>=0;i--){
            if(i+maxJump+1<n){
                if(s[i+maxJump+1]=='0'&&dp[i+maxJump+1]==1)
                count-=1;
            }
            if(i+minJump<n){
                if(s[i+minJump]=='0'&&dp[i+minJump]==1)
                count+=1;
            }
            if(count>0)
            dp[i]=1;
        }
        return dp[0]==1;
    }
};