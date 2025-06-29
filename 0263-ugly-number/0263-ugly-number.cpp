class Solution {
public:
    bool isUgly(int x) {
      if(x<=0) return false;
    //   vector<int>ans(n+1,1);
    //   ans[0]=ans[1]=0;
    //   for(int i=2;i<=sqrt(n);i++){
    //     if(ans[i]){
    //         for(int j=i*i;j<=n;j+=i){
    //             ans[j]=false;
    //         }
    //     }
    //   }
    //   for(int i=7;i<n+1;i++){
    //     if(ans[i]&&n%i==0)
    //     return false;
    //   }
    //   return true;

    while(x%2==0)
    x=x/2;
    while(x%3==0)
    x=x/3;
    while(x%5==0)
    x=x/5;
    return x==1;
    }
};