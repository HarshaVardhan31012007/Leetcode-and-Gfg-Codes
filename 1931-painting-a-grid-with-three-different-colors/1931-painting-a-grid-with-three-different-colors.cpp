class Solution {
public:
    // const int mod=1e9+7;
    // void build(vector<string>&str,string &temp,int m){
    //     if(m==0){
    //         str.push_back(temp);
    //         return;
    //     }
    //     char ch[3]={'R','G','B'};
    //     for(int i=0;i<3;i++){
    //         if(temp.empty()||temp.back()!=ch[i]){
    //             temp.push_back(ch[i]);
    //             build(str,temp,m-1);
    //             temp.pop_back();
    //         }
    //     }
    // }
    // int solve(int m,int n,int prev,int size,vector<string>&str,vector<vector<int>>&dp){
    //     if(m==0) return 1;
    //     if(dp[m][prev]!=-1) return dp[m][prev];
    //     string last=str[prev];
    //     int ans=0;
    //     for(int i=0;i<size;i++){
    //         if(i==prev) continue;
    //         string curr=str[i];
    //         bool flag=true;
    //         for(int j=0;j<n;j++){
    //             if(curr[j]==last[j]){
    //                 flag=false;
    //                 break;
    //             }
    //         }
    //         if(flag){
    //             ans=(ans+solve(m-1,n,i,size,str,dp))%mod;
    //         }
    //     }
    //     return dp[m][prev]=ans;
    // }
    // int colorTheGrid(int m, int n) {
    //     swap(m,n);//both are same answer as m constraint is less than n so like that
    //     vector<string>str;
    //     string temp="";
    //     build(str,temp,n);
    //     int ans=0;
    //     int size=str.size();
    //     vector<vector<int>>dp(m+1,vector<int>(size+1,-1));
    //     for(int i=0;i<size;i++){
    //         ans=(ans+solve(m-1,n,i,size,str,dp))%mod;
    //     }
    //     return ans;
    // }


    const int mod=1e9+7;
    void build(vector<int>&str,int temp,int m){
        if(m==0){
            str.push_back(temp);
            return;
        }
        for(int i=0;i<3;i++){
            if(temp==-1){
                build(str,i,m-1);
            }
            else if(temp%3!=i){
                build(str,temp*3+i,m-1);
            }
        }
    }
    int solve(int m,int n,int prev,int size,vector<int>&str,vector<vector<int>>&dp){
        if(m==0) return 1;
        if(dp[m][prev]!=-1) return dp[m][prev];
        int llast=str[prev];
        int ans=0;
        for(int i=0;i<size;i++){
            if(i==prev) continue;
            int curr=str[i];
            bool flag=true;
            int last=llast;
            for(int j=0;j<n;j++){
                if(curr%3==last%3){
                    flag=false;
                    break;
                }
                curr/=3;last/=3;
            }
            if(flag){
                ans=(ans+solve(m-1,n,i,size,str,dp))%mod;
            }
        }
        return dp[m][prev]=ans;
    }
    int colorTheGrid(int m, int n) {
        swap(m,n);//both are same answer as m constraint is less than n so like that
        vector<int>str;
        int temp=-1;
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