class Solution {
public:
        // const int mod=1e9+7;
        // bool check(long long int n,int k){
        //     int count=0;
        //     while(n!=0){
        //         n=(n&(n-1));
        //         count++;
        //     }
        //     return count==k;
        // }
        // long long find1(vector<int>&freq){
        //     long long ans=1;
        //     for(auto &num:freq){
        //         ans=(ans*find(num));
        //     }
        //     return ans;
        // }
        // void solve(vector<int>&nums,int m,int &k,long long int sum,int i,long long int prod,long long int &ans,long long int &no,vector<int>&freq){
        //     if(m==0) {
        //         if(check(sum,k)){
        //             long long count=no;
        //             long long count1=find1(freq);
        //             count=count/count1;
        //             while(count--)
        //         ans=(ans+prod%mod)%mod;
        //         }
        //         return;
        //     }
        //     if(i>=nums.size()||m<0) return;
        //     freq[i]++;
        //    // solve(nums,m-1,k,sum+(1LL<<i),i+1,(prod*nums[i]%mod)%mod,ans,no,freq);
        //    //this is duplicate call because inc and goes right//same situation can be come with below two calls//current ko inc karo in one call and exc current and goes right in other call
        //     solve(nums,m-1,k,sum+(1LL<<i),i,(prod*nums[i]%mod)%mod,ans,no,freq);//pow(2,i) gives double it casts to long long some precision lost so use 1LL<<i
        //     freq[i]--;
        //     solve(nums,m,k,sum,i+1,prod,ans,no,freq);
        // }
        // long long int find(int m){
        //     if(m==1||m==0) return 1;
        //     return (1LL*m*find(m-1))%mod;
        // }
        // int magicalSum(int m, int k, vector<int>& nums) {
        // long long int ans=0;
        // long long int no=find(m);
        // vector<int>freq(nums.size(),0);
        // solve(nums,m,k,0,0,1,ans,no,freq);
        // return ans%mod;
        // }



    // const int mod=1e9+7;
    // unordered_map<string,long long>mpp;
    // bool check(long long int n,int k){
    //     int count=0;
    //     while(n!=0){
    //         n=(n&(n-1));
    //         count++;
    //     }
    //     return count==k;
    // }

    // long long solve(vector<int>&nums,int m,int &k,long long int sum){
    //      if(m==0) {
    //         return check(sum,k);
    //      }
    //      string key=to_string(m)+to_string(sum);
    //      if(mpp.count(key))
    //      return mpp[key];
    //      long long int totalSum=0;
    //      for(int j=0;j<nums.size();j++){
    //         long long prod=1LL*nums[j]*solve(nums,m-1,k,sum+pow(2,j));
    //         totalSum=(totalSum+prod)%mod;
    //      }
    //      return mpp[key]=totalSum;
    // }

    // int magicalSum(int m, int k, vector<int>& nums) {
    //   return (int)(solve(nums,m,k,0)%mod);
    // }



    //in above two methods decimal addition takes time because it didnt avoid overlapping subproblems
    //so use binary additions avoid overlapping subproblems

    //5 4 3 2 1,m=3,k=2
    // approach 1 //decimal addition (m,sum) // 0 inc and 1 exc ,at 3 we have  (2,1) 
    //0 exc and 1 inc ,at 3 we have (2,2) both are not overlapping 
    //approach 2//binary addition (m,k,i,binarysum)
    // 0 inc (1 time) and 1 exc (0 times) ,at 3 we have (2,1,2,0)  
    // 0 exc (0 time) and 1 inc(1 time) ,at 3 we have (2,1,2,0)

    //these are overlapping by this approach so dp is useful here but in decimal it si not useful
   
        typedef long long ll;
        int mod=1e9+7;
        vector<ll>fact;
        vector<ll>inverseFact;
        map<tuple<int,int,int,int>,ll>dp;
        ll findPower(ll a,ll b){
            // if(b==0) return 1;
            // ll ans=1;
            // if(b&1){
            //     ans=(ans*a)%mod;
            // }
            // ll recans=findPower(a,b>>1)%mod;
            // recans=(recans*recans)%mod;
            // return (ans*recans)%mod;


            if(b==0) return 1;
            ll ans=1;
            if(b&1){
                ans=(ans*a)%mod;
            }
            return (ans*findPower((a*a)%mod,b>>1))%mod;
        }
        ll nCr(int n,int r){
            return (((1LL*fact[n]*inverseFact[r])%mod)*inverseFact[n-r])%mod;
        }
        ll solve(int m,int k,int i,int binarysum,vector<int>&nums){
            if(m==0&&__builtin_popcount(binarysum)==k){
                return 1;
            }
            if(m==0||k==0||i>=nums.size()) return 0;
            auto key=make_tuple(m,k,i,binarysum);
            if(dp.count(key))
            return dp[key];
            ll totalsum=0;
            for(int freq=0;freq<=m;freq++){
                int newbsum=binarysum+freq;
                ll recall=solve(m-freq,k-(newbsum&1),i+1,newbsum>>1,nums)%mod;
                ll prod=(nCr(m,freq)*recall)%mod;
                prod=(findPower(nums[i],freq)*prod)%mod;
                totalsum=(totalsum+prod)%mod;
            }
            return dp[key]=totalsum;
        }
        int magicalSum(int m, int k, vector<int>& nums) {
             fact.assign(m+1,1);
             inverseFact.assign(m+1,1);
             for(int i=2;i<=m;i++){
                fact[i]=(fact[i-1]*i)%mod;
             }
             for(int i=2;i<=m;i++){
                inverseFact[i]=findPower(fact[i],mod-2);
             }
             return (int)solve(m,k,0,0,nums);
        }
};