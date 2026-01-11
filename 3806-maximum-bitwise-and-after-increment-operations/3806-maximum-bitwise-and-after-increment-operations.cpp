class Solution {
public:
    #define ll long long
    ll cost(int x,int target){
        int y=x;
        for(int b=30;b>=0;b--){
            if((target>>b)&1){
                int need=1LL<<b;
                int block=1LL<<(b+1);
                int rem=y%block;
                if(rem<need) y+=need-rem;
            }
        }
        return y-x;
    }
    int maximumAND(vector<int>& nums, int k, int m) {
       int ans=0;
       for(int b=30;b>=0;b--){
          int target=ans|(1<<b);
          vector<ll>v;
          for(int x:nums) v.push_back(cost(x,target));
          sort(v.begin(),v.end());
          ll sum=0;
          for(int i=0;i<m;i++)
          sum+=v[i];
          if(sum<=k) ans=target;
       }
       return ans;
    }
};