class Solution {
public:
    // string check(string &s,int i,int j){
    //     while(i>=0&&j<s.length()){
    //         if(s[i]==s[j]){
    //             i--;j++;
    //         }
    //         else
    //         break;
    //     }
    //     return s.substr(i+1,j-i-1);
    // }
    // string longestPalindrome(string s) {
    //     string ans="";
    //     for(int i=0;i<s.length();i++){
    //         string temp=check(s,i,i);
    //         if(temp.length()>ans.length()) ans=temp;
    //         temp=check(s,i,i+1);
    //         if(temp.length()>ans.length()) ans=temp;
    //     }
    //     return ans;
    // }


    
    bool checkpalindrome(string &s,int i,int j,vector<vector<int>>&dp){
       if(i>=j) return true; 
       if(s[i]==s[j])
       return dp[i][j]=checkpalindrome(s,i+1,j-1,dp);
       else{
          return false;
       }
    }
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        string ans="";
        for(int i=0;i<s.length();i++){
           for(int j=i;j<s.length();j++){
               if(j-i+1>ans.size()&&checkpalindrome(s,i,j,dp)){
                   ans=s.substr(i,j-i+1);
               }
           }
        }
        return ans;
    }
};