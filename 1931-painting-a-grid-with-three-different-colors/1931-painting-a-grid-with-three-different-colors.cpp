class Solution {
public:
    const int mod=1e9+7;
    void build(vector<string>&str,string &temp,int m){
        if(m==0){
            str.push_back(temp);
            return;
        }
        char ch[3]={'R','G','B'};
        for(int i=0;i<3;i++){
            if(temp.empty()||temp.back()!=ch[i]){
                temp.push_back(ch[i]);
                build(str,temp,m-1);
                temp.pop_back();
            }
        }
    }
    int solve(int m,int n,int prev,int size,vector<string>&str,vector<vector<int>>&dp){
        if(m==0) return 1;
        if(dp[m][prev]!=-1) return dp[m][prev];
        string last=str[prev];
        int ans=0;
        for(int i=0;i<size;i++){
            if(i==prev) continue;
            string curr=str[i];
            bool flag=true;
            for(int j=0;j<n;j++){
                if(curr[j]==last[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans=(ans+solve(m-1,n,i,size,str,dp))%mod;
            }
        }
        return dp[m][prev]=ans;
    }
    int colorTheGrid(int m, int n) {
        swap(m,n);
        vector<string>str;
        string temp="";
        build(str,temp,n);
        int ans=0;
        int size=str.size();
        vector<vector<int>>dp(m+1,vector<int>(size+1,-1));
        for(int i=0;i<size;i++){
            ans=(ans+solve(m-1,n,i,size,str,dp))%mod;
        }
        return ans;
    }
};