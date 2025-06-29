class Solution {
public:
    // bool check(int n){
    //     while(n%2==0)
    //     n=n/2;
    //     while(n%3==0)
    //     n=n/3;
    //     while(n%5==0)
    //     n=n/5;
    //     return n==1;
    // }
    // int nthUglyNumber(int n) {
    //     int i=0;int j=1;
    //     while(i<n){
    //         if(check(j)){
    //             i++;j++;
    //         }
    //         else
    //         j++;
    //     }
    //     return j-1;
    // }


    
    int nthUglyNumber(int n) {
      //elements may repeat //use set 2*3 3*2 ssame
    //   set<long long int>st;
    //   st.insert(1);
    //   n--;
    //   while(n--){
    //     long long front=*st.begin();
    //     st.erase(st.begin());
    //     st.insert(front*2);
    //     st.insert(front*3);
    //     st.insert(front*5);
    //   }
    //   return *st.begin();


    vector<int>dp(n,0);
    dp[0]=1;
    int x=0;int y=0;int z=0;
    for(int i=1;i<n;i++){
       dp[i]=min({2*dp[x],3*dp[y],5*dp[z]});
       if(dp[i]==2*dp[x]) x++;
       if(dp[i]==3*dp[y]) y++;
       if(dp[i]==5*dp[z]) z++;
    }
       return dp[n-1];
    }
};