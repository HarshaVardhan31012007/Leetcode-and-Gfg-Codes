class Solution {
public:
    bool dfs(int i,int maxi,string &s,int &n,int &minJump,int &maxJump,vector<int>&visited){
        visited[i]=1;
        if(i==(n-1)) return true;
        int end=i+maxJump;
        int start=(i+minJump);
        if(start<=maxi) start=maxi+1;
        int maxi1=min(end,n-1);
        for(int j=start;j<=min(end,n-1);j++){
            if(visited[j]==0&&s[j]=='0'){
                bool ans=dfs(j,maxi1,s,n,minJump,maxJump,visited);
                if(ans) return true;
                maxi1=max(maxi1,min(j+maxJump,n-1));
            }
        }
        return false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        if(s[n-1]=='1') return false;
        vector<int>visited(n,0);
        return dfs(0,0,s,n,minJump,maxJump,visited);
    }
};