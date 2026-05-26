class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        if(s[n-1]=='1') return false;
        vector<int>visited(n,0);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        int maxi=0;
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            if(idx==(n-1)) return true;
            for(int j=max(maxi+1,idx+minJump);j<=min(idx+maxJump,n-1);j++){
                maxi=max(maxi,j);
                if(visited[j]==0&&s[j]=='0'){
                    q.push(j);
                    visited[j]=1;
                }
            }
        }
        return false;
    }
};