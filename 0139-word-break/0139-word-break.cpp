class Solution {
public:
    bool check(string &temp,vector<string>& wordDict){
        for(auto &i:wordDict){
           if(i==temp)
           return true;
        }
        return false;
    }
    bool solve(int i,string &s,vector<string>& wordDict,vector<int>&dp){
        if(i==s.size()) return 1;
        if(dp[i]!=-1)
        return dp[i];
        string temp="";
        bool flag=false;
        for(int j=i;j<s.length();j++){
            temp=temp+s[j];
            if(check(temp,wordDict)){
                flag=flag||solve(j+1,s,wordDict,dp);
            }
        }
        return dp[i]=flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length()+1,-1);
        return solve(0,s,wordDict,dp);
    }
};