class Solution {
public:
    // bool solve(string &s,int i,vector<int>&dp,unordered_set<string>&st){
    //     if(i>=s.length()) return true;
    //     if(dp[i]!=-1) return dp[i];
    //     string temp="";bool ans=false;
    //     for(int j=i;j<s.length();j++){
    //         temp+=s[j];
    //         if(st.find(temp)!=st.end()){
    //            ans=ans||solve(s,j+1,dp,st);
    //         }
    //     }
    //     return dp[i]=ans;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string>st;
    //     for(auto &each:wordDict)
    //     st.insert(each);
    //     vector<int>dp(s.length()+1,-1);
    //     return solve(s,0,dp,st);
    // }


    
    
     bool solve(string &s,int i,vector<int>&dp,unordered_map<string,int>&mpp){
        if(i>=s.length()) return true;
        if(dp[i]!=-1) return dp[i];
        string temp="";bool ans=false;
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(mpp.find(temp)!=mpp.end()){
               ans=ans||solve(s,j+1,dp,mpp);
            }
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mpp;
        for(auto &each:wordDict)
        mpp[each]=1;
        vector<int>dp(s.length()+1,-1);
        return solve(s,0,dp,mpp);
    }
};