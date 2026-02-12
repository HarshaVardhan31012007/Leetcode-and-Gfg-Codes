class Solution {
public:
    bool check(string &a,string &b){
        if(a.size()+1!=b.size()) return  false;
        int i=0;
        int j=0;
        bool flag=1;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else if(flag){
                j++;
                flag=0;
            }
            else
            break;
        }
        return i==a.size();
    }
    int solve(vector<string>&words,int i,int prev,vector<vector<int>>&dp){
        if(i>=words.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int inc=0;
        if(prev==-1||check(words[prev],words[i])){
            inc=1+solve(words,i+1,i,dp);
        }
        int exc=solve(words,i+1,prev,dp);
        return dp[i][prev+1]=max(inc,exc);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[&](string &a,string &b){
            if(a.size()!=b.size())
            return a.size()<b.size();
            return a<b;
        });
        int n=words.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(words,0,-1,dp);
    }
};