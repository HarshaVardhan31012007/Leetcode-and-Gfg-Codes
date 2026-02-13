class Solution {
public:
    bool ispalindrom(string &s,int i,int j,vector<vector<int>>&ispalindrome){
        if(i>=j) return ispalindrome[i][j]=true;
        if(ispalindrome[i][j]!=-1) return ispalindrome[i][j];
        if(s[i]==s[j]){
            return ispalindrome[i][j]=ispalindrom(s,i+1,j-1,ispalindrome);
        }
        else
        return ispalindrome[i][j]=false;
    }
    int solve(string &s,int i,vector<vector<int>>&ispalindrome,vector<int>&dp){
        if(i>=s.length()){
           return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<s.length();k++){
            if(ispalindrome[i][k]){
                int reccall=solve(s,k+1,ispalindrome,dp);
                if(reccall!=INT_MAX&&k<s.length()-1)
                ans=min(ans,1+reccall);
                if(reccall!=INT_MAX&&k==s.length()-1)
                ans=min(ans,reccall);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        vector<vector<int>>ispalindrome(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ispalindrome[i][j]=ispalindrom(s,i,j,ispalindrome);
            }
        }
        vector<int>dp(n+1,-1);
        return solve(s,0,ispalindrome,dp);
    }
};



// class Solution {
// public:
//     bool ispalindrom(string &s,int i,int j,vector<vector<int>>&ispalindrome){
//         while(i>=0&&j<s.length()&&s[i]==s[j]){
//             ispalindrom[i][j]=1;
//             i--;
//             j++;
//         }
//     }
//     int solve(string &s,int i,vector<vector<int>>&ispalindrome,vector<int>&dp){
//         if(i>=s.length()){
//            return 0;
//         }
//         if(dp[i]!=-1) return dp[i];
//         int ans=INT_MAX;
//         for(int k=i;k<s.length();k++){
//             if(ispalindrome[i][k]){
//                 int reccall=solve(s,k+1,ispalindrome,dp);
//                 if(reccall!=INT_MAX&&k<s.length()-1)
//                 ans=min(ans,1+reccall);
//                 if(reccall!=INT_MAX&&k==s.length()-1)
//                 ans=min(ans,reccall);
//             }
//         }
//         return dp[i]=ans;
//     }
//     int minCut(string s) {
//         int n=s.length();
//         vector<vector<int>>ispalindrome(n,vector<int>(n,0));
//         for(int i=0;i<n;i++){
//             ispalindrom(s,i,i,ispalindrome);
//             ispalindrom(s,i,i+1,ispalindrome);
//         }
//         vector<int>dp(n+1,-1);
//         return solve(s,0,ispalindrome,dp);
//     }
// };