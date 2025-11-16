class Solution {
public:
    int countBinarySubstrings(string s) {
        // int n=s.length();
        // vector<int>prefix(n,0);
        // prefix[0]=(s[0]=='1'?1:0);
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]+(s[i]='1'?1:0);
        // }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int ones=prefix[j]-(i>0?prefix[i-1]:0);
        //         int zeros=(j-i+1)-ones;
        //         if(ones!=zeros){
        //            j+=(abs(ones-zeros)-1);
        //         }
        //         else{
        //            ans++;
        //         }
        //     }
        // }
        // return ans;



        // int n=s.length();
        // vector<int>v;
        // int i=0;
        // while(i<n){
        //     int c=0;
        //     while(i<n&&s[i]=='0'){
        //         c++;i++;
        //     }
        //     if(c>0) v.push_back(c);
        //     c=0;
        //     while(i<n&&s[i]=='1'){
        //         c++;i++;
        //     }
        //     if(c>0) v.push_back(c);
        // }
        // int ans=0;
        // int prev=v[0];
        // for(int i=1;i<v.size();i++){
        //      int curr=v[i];
        //      ans+=min(prev,curr);
        //      prev=curr;
        // }
        // return ans;



       
        int ans=0;
        int curr=1;int prev=0;
        for(int i=1;i<s.length();i++){
             if(s[i]==s[i-1]) curr++;
             else
             ans+=min(prev,curr),prev=curr,curr=1;
        }
        ans+=min(prev,curr);
        return ans;
    }
};