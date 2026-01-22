class Solution {
public:
     string longestCommonSubsequence(string a, string b) {
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                    if(a[i]==b[j]){
                        dp[i][j]=1+dp[i+1][j+1];
                    }
                    else{
                        dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                    }
            }
        }
        int i=0,j=0;
        string ans="";
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]){
               ans+=a[i];
               i++;j++;
            }
            else{
                int maxi=INT_MIN;int x=i,y=j;char ch=0;
                if(dp[i][j+1]>maxi){
                    maxi=dp[i][j+1];
                    x=i;
                    y=j+1;
                    ch=b[j];
                }
                if(dp[i+1][j]>maxi){
                    maxi=dp[i+1][j];
                    x=i+1;
                    y=j;
                    ch=a[i];
                }
                ans+=ch;
                i=x;j=y;
            }
        }
        ans+=a.substr(i);
        ans+=b.substr(j);
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return longestCommonSubsequence(str1,str2);
    }
};