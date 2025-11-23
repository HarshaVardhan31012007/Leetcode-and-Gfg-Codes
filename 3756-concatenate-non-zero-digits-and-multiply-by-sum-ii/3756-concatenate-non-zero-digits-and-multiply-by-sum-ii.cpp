class Solution {
public:
    // const int mod=1e9+7;
    // vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    //       long long int n=s.length();
    //       vector<long long int>psum(n,0);
    //       psum[0]=(s[0]-'0');
    //       for(long long int i=1;i<n;i++){
    //         psum[i]=(psum[i-1]+(s[i]-'0'))%mod;
    //       }
    //       vector<string>pnum(n,"");
    //       pnum[0]=s[0];
    //       for(int i=1;i<n;i++){
    //         pnum[i]=pnum[i-1];
    //         if(s[i]!='0'){
    //             pnum[i]+=s[i];
    //         }
    //       }
    //       vector<int>ans(queries.size(),0);
    //       for(int i=0;i<queries.size();i++){
    //           long long int a=queries[i][0];
    //           long long int b=queries[i][1];
    //           string m=pnum[b];
    //           string n="";
    //           if(a>0){
    //              n=pnum[a-1];
    //           }
    //           long long int num=0;
    //           int idx=n.length();
    //           while(idx<m.length()){
    //               num=(num*10+(m[idx]-'0'))%mod;
    //               idx++;
    //           }
    //           long long int sum=0;
    //           if(a==0)
    //           sum=psum[b];
    //           else
    //           sum=psum[b]-psum[a-1];
    //           ans[i]=(int)((sum%mod*num%mod)%mod);
    //       }
    //       return ans;
    // }



            // const int mod=1e9+7;
            // vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
            //     long long int n=s.length();
            //     vector<long long int>psum(n,0);
            //     psum[0]=(s[0]-'0');
            //     for(long long int i=1;i<n;i++){
            //         psum[i]=(psum[i-1]+(s[i]-'0'))%mod;
            //     }
            //     vector<int>ans(queries.size(),0);
            //     for(int i=0;i<queries.size();i++){
            //         long long int a=queries[i][0];
            //         long long int b=queries[i][1];
            //         long long int num=0;
            //         for(long long j=a;j<=b;j++){
            //             if(s[j]!='0')
            //             num=(num*10+(s[j]-'0'))%mod;
            //         }
            //         long long int sum=0;
            //         if(a==0)
            //         sum=psum[b];
            //         else
            //         sum=psum[b]-psum[a-1];
            //         ans[i]=(int)((sum%mod*num%mod)%mod);
            //     }
            //     return ans;
            // }
   

    //          const int mod=1e9+7;
    // vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    //       long long int n=s.length();
    //       vector<long long int>psum(n,0);
    //       psum[0]=(s[0]-'0');
    //       for(long long int i=1;i<n;i++){
    //         psum[i]=(psum[i-1]+(s[i]-'0'))%mod;
    //       }
    //       vector<long long int>pnum(n,0);
    //       pnum[0]=(s[0]-'0');
    //       for(long long int i=1;i<n;i++){
    //         pnum[i]=pnum[i-1];
    //         if(s[i]!='0'){
    //             pnum[i]=(pnum[i]*10+(s[i]-'0'))%mod;
    //         }
    //       }
    //       vector<int>ans(queries.size(),0);
    //       for(int i=0;i<queries.size();i++){
    //           long long int a=queries[i][0];
    //           long long int b=queries[i][1];
    //           long long int m=pnum[b];
    //           long long int n=0;
    //           if(a>0){
    //              n=pnum[a-1];
    //           }
    //           long long int num=0;
    //           long long int c=1;
    //           while(m!=n){
    //              num=(num+c*(m%10));
    //              c=(c*10);
    //              m=m/10;
    //           }
    //           long long int sum=0;
    //           if(a==0)
    //           sum=psum[b];
    //           else
    //           sum=psum[b]-psum[a-1];
    //           ans[i]=(int)((sum%mod*num%mod)%mod);
    //       }
    //       return ans;
    // }
          



    const int mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
         int n=s.length();
         vector<long long>sum(n,0);//prefix sum
         vector<long long>num(n,0);//actual number after concatenation
         vector<long long>count(n,0);//non zero count
         vector<long long>pow10(n+1,1);//for 10 powers
         for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%mod;
         }
         sum[0]=(s[0]-'0');
         count[0]=(s[0]=='0'?0:1);
         num[0]=(s[0]-'0');
         int c=1;
         for(int i=1;i<n;i++){
            sum[i]=(sum[i-1]+(s[i]-'0'))%mod;
            count[i]=count[i-1];
            num[i]=num[i-1];
            if(s[i]!='0'){
                count[i]=count[i-1]+1;
                num[i]=(num[i]*10+(s[i]-'0'))%mod;
            }
         }
         vector<int>ans;
         for(auto &query:queries){
            int i=query[0];int j=query[1];
            long long csum=sum[j]-(i>0?sum[i-1]:0);
            long long ccount=count[j]-(i>0?count[i-1]:0);
            long long cnum=(num[j]-(i>0?(pow10[ccount]*num[i-1]):0)%mod+mod)%mod;
            ans.push_back((csum*cnum)%mod);
         }
         return ans;
    }
};