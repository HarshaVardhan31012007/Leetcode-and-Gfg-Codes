class Solution {
public:
    // bool checkPalindrome(string &k,int i,int j){
    //     while(i<j){
    //         if(k[i]!=k[j]){
    //             return false;
    //         }
    //         i++;j--;
    //     }
    //     return true;
    // }
    // string longestPalindrome(string s) {
    //     string ans="";
    //     for(int i=0;i<s.length();i++){
    //         for(int j=i;j<s.length();j++){
    //              if(j-i+1>ans.size()&&checkPalindrome(s,i,j)){
    //                 ans=s.substr(i,j-i+1);
    //              }
    //         }
    //     }
    //     return ans;
    // }

    // int maxlen=1;int start=0;
    // bool solve(string &s,int i,int j,vector<vector<int>>&dp){
    //     if(i>=j) return true;
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     bool flag=0;
    //     if(s[i]==s[j])
    //     flag=solve(s,i+1,j-1,dp);
    //     if(flag){
    //         if(maxlen<j-i+1){
    //             start=i;
    //             maxlen=j-i+1;
    //         }
    //     }
    //     return dp[i][j]=flag;
    // }
    // string longestPalindrome(string s) {
    //     int n=s.length();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1)); 
    //     for(int i=0;i<s.length();i++){
    //         for(int j=i;j<s.length();j++){
    //             solve(s,i,j,dp);
    //         }
    //     }
    //     return s.substr(start,maxlen);
    // }

     
    // string ans="";
    // void expand(string &s,int i,int j){
    //  while(i>=0&&j<s.length()&&s[i]==s[j]){
    //       i--;j++;
    //  }
    //  if(ans.length()<j-i-1)
    //  ans=s.substr(i+1,j-i-1);
    // }
    // string longestPalindrome(string s) {
    //   for(int i=0;i<s.length();i++){
    //     //odd case
    //     expand(s,i,i);
    //     //even case
    //     expand(s,i,i+1);
    //   }
    //   return ans;
    // }



    string longestPalindrome(string s){
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int idx=0;int idx1=0;
        for(int i=0;i<s.length();i++)
        dp[i][i]=1;
        for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            idx=i;idx1=i+1;
        }
        }

        for(int diff=2;diff<n;diff++){  
            for(int i=0,j=i+diff;j<n;i++,j++){
                if(s[i]==s[j]&&dp[i+1][j-1]==1){
                dp[i][j]=1;
                if(idx1-idx+1<j-i+1){
                idx=i;idx1=j;
                }
                }
            }
        }
        return s.substr(idx,idx1-idx+1);
    }
};