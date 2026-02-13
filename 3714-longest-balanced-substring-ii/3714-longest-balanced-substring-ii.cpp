class Solution {
public:
    int largestthree(string &s){
        int n=s.length();
        map<pair<int,int>,int>mpp;
        int a=0,b=0,c=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;
            if(a==b&&b==c)
            ans=max(ans,i+1);
            if(!mpp.count({a-b,b-c}))
            mpp[{a-b,b-c}]=i;
            else
            ans=max(ans,i-mpp[{a-b,b-c}]);
        }
        return ans;
    }
    int largestsingle(string &s){
        int n=s.length();
        int ans=1;
        int s1=0;int e=0;
        for(int i=0;i<n-1;i++){
           if(s[i]==s[i+1]){
              e++;
           }
           else{
              ans=max(ans,e-s1+1);
              s1=i+1;
              e=i+1;
           }
        }
        ans=max(ans,e-s1+1);
        return ans;
    }
    int largestdouble(string &s){
        int n=s.length();
        map<pair<int,int>,int>mpp;
        map<pair<int,int>,int>mpp1;
        map<pair<int,int>,int>mpp2;
        int a=0,b=0,c=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;
            if(a==b&&c==0)
            ans=max(ans,i+1);
            if(b==c&&a==0)
            ans=max(ans,i+1);
            if(c==a&&b==0)
            ans=max(ans,i+1);
            if(mpp.count({a-b,c}))
            ans=max(ans,i-mpp[{a-b,c}]);
            else
            mpp[{a-b,c}]=i;
            if(mpp1.count({b-c,a}))
            ans=max(ans,i-mpp1[{b-c,a}]);
            else
            mpp1[{b-c,a}]=i;
            if(mpp2.count({a-c,b}))
            ans=max(ans,i-mpp2[{a-c,b}]);
            else
            mpp2[{a-c,b}]=i;
        }
        return ans;
    }
    int longestBalanced(string s) {
         int ans=largestthree(s);
         ans=max(ans,largestsingle(s));
         ans=max(ans,largestdouble(s));
         return ans;
    }
};