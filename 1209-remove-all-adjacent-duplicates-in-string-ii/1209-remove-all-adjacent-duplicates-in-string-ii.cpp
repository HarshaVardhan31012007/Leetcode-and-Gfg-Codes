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



        // int n=s.length();
        // int i=0;int j=0;
        // vector<int>dp(n,1);
        // while(j<n){
        //     s[i++]=s[j];
        //     int idx=i-1;
        //     if(idx>0&&s[idx]==s[idx-1]){
        //         dp[idx]=dp[idx-1]+1;
        //     }
        //     else
        //     dp[idx]=1;
        //     if(dp[idx]==k)
        //     i-=k;
        //     j++;
        // }
        // return s.substr(0,i);



        // int n=s.length();
        // int i=n-1;int j=n-1;
        // stack<pair<char,int>>st;
        // for(int i=n-1;i>=0;i--){
        //     if(st.empty()){
        //         st.push({s[i],1});
        //     }
        //     else{
        //         if(st.top().first==s[i]){
        //             st.top().second++;
        //         }
        //         else{
        //             st.push({s[i],1});
        //         }
        //     }
        //     if(st.top().second==k) st.pop();
        // }
        // string ans="";
        // while(!st.empty()){
        //     char ch=st.top().first;
        //     int c=st.top().second;
        //     st.pop();
        //     while(c--){
        //         ans+=ch;
        //     }
        // }
        // return ans;




        int n=s.length();
        int i=n-1;int j=n-1;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            if(v.empty()){
                v.push_back({s[i],1});
            }
            else if(v.back().first==s[i]){
                v.back().second++;
            }
            else
             v.push_back({s[i],1});
             if(v.back().second==k) v.pop_back();
        }
        string ans="";
        for(auto &each:v){
            ans+=string(each.second,each.first);
        }
        return ans;
    }
};