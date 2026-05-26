class Solution {
public:
    bool dfs(int i,int mini,int maxi,string &s,int &n,int &minJump,int &maxJump,vector<int>&visited){
        visited[i]=1;
        if(i==(n-1)) return true;
        bool ans=false;
        int maxi1=maxi+1;
        for(int j=mini;j<=min(maxi,n-1);j++){
           if(visited[j]==0&&s[j]=='0'){
             ans=ans||dfs(j,max(maxi1,j+minJump),j+maxJump,s,n,minJump,maxJump,visited);
             maxi1=max(maxi1,j+maxJump+1);
           }
        }
        return ans;
    }
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        if(s[n-1]=='1') return false;
        vector<int>visited(n,0);
        visited[0]=1;
        return dfs(0,minJump,maxJump,s,n,minJump,maxJump,visited);
    }
};