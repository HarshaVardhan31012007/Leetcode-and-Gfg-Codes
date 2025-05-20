class Solution {
public:
    // int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp){
    //     if(j==word2.size()) return word1.size()-i;
    //     if(i==word1.size()) return word2.size()-j;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i]==word2[j])
    //     return solve(word1,word2,i+1,j+1,dp);
    //     else
    //     return 1+min(solve(word1,word2,i+1,j+1,dp),min(solve(word1,word2,i,j+1,dp),solve(word1,word2,i+1,j,dp)));
    // }
    // int minDistance(string word1, string word2) {
    // vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
    //    return solve(word1,word2,0,0,dp); 
    // }

    //  int solve(string &word1,string &word2){
    //     vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
    //     for(int i=0;i<word1.size()+1;i++){
    //         dp[i][word2.size()]=word1.size()-i;
    //     }
    //     for(int j=0;j<word2.size()+1;j++){
    //         dp[word1.size()][j]=word2.size()-j;
    //     }
    //     for(int i=word1.size()-1;i>=0;i--){
    //        for(int j=word2.size()-1;j>=0;j--){
    //          if(word1[i]==word2[j])
    //          dp[i][j]=dp[i+1][j+1];
    //          else{
    //             int op1=dp[i][j+1];
    //             int op2=dp[i+1][j];
    //             int op3=dp[i+1][j+1];
    //             dp[i][j]=1+min({op1,op2,op3});
    //          }
    //        }
    //     }
    //     return dp[0][0];
    //  }
    //  int minDistance(string word1, string word2) {
    //    return solve(word1,word2); 
    // }


    int solve(string &word1,string &word2){
        vector<int>curr(word2.size()+1,-1);
        vector<int>next(word2.size()+1,-1);
            for(int j=0;j<word2.size()+1;j++){
            next[j]=word2.size()-j;
        }
        for(int i=word1.size()-1;i>=0;i--){
           for(int j=word2.size();j>=0;j--){
            if(j==word2.size()){
                curr[j]=word1.size()-i;
               continue;
            }
             if(word1[i]==word2[j])
            curr[j]=next[j+1];
             else{
                int op1=curr[j+1];
                int op2=next[j];
                int op3=next[j+1];
                curr[j]=1+min({op1,op2,op3});
             }
           }
           next=curr;
        }
        return next[0];
     }
     int minDistance(string word1, string word2) {
       return solve(word1,word2); 
    }
};