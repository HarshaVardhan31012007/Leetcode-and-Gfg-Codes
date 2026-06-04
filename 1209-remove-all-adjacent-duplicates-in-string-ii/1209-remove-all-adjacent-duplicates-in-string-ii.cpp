class Solution {
public:
    string removeDuplicates(string s, int k) {
        // int n=s.length();
        // int i=0;int j=0;
        // while(j<n){
        //     s[i++]=s[j];
        //     if(i>=k){
        //         bool same=true;
        //         for(int p=i-2;p>=i-k;p--){
        //            if(s[p]!=s[p+1]){
        //               same=false;
        //               break;
        //            }
        //         }
        //         if(same)
        //         i-=k;
        //     }
        //     j++;
        // }
        // return s.substr(0,i);



        int n=s.length();
        int i=0;int j=0;
        vector<int>dp(n,1);
        while(j<n){
            s[i++]=s[j];
            int idx=i-1;
            if(idx>0&&s[idx]==s[idx-1]){
                dp[idx]=dp[idx-1]+1;
            }
            else
            dp[idx]=1;
            if(dp[idx]==k)
            i-=k;
            j++;
        }
        return s.substr(0,i);
    }
};