class Solution {
public:
    // int find(priority_queue<long long>pq,priority_queue<long long,vector<long long>,greater<>>pq1,long long k,vector<int>&nums,long long &n,long long sum,long long sum1){
    //     long long j=n;
    //     long long count=k;
    //     while(count--){
    //         pq.push(nums[j]);
    //         sum+=nums[j];
    //         j++;
    //     }
    //     while(j<2*n){
    //         pq1.push(nums[j]);
    //         sum1+=nums[j];
    //         j++;
    //     }
    //     while(pq.size()>n){
    //         sum-=pq.top();
    //         pq.pop();
    //     }
    //      while(pq1.size()>n){
    //         sum1-=pq1.top();
    //         pq1.pop();
    //     }
    //     return sum-sum1;
    // }
    // long long minimumDifference(vector<int>& nums) {
    //     long long n=nums.size()/3;
    //     priority_queue<long long>pq;
    //     priority_queue<long long,vector<long long>,greater<>>pq1;
    //     long long sum=0;long long sum1=0;
    //     for(int i=0;i<n;i++){
    //        pq.push(nums[i]);
    //        sum+=nums[i];
    //     }
    //     for(int i=2*n;i<nums.size();i++){
    //         pq1.push(nums[i]);
    //         sum1+=nums[i];
    //     }
    //     long long ans=INT_MAX;
    //     for(long long i=0;i<=n;i++){
    //         long long curr=find(pq,pq1,i,nums,n,sum,sum1);
    //         ans=min(ans,curr);
    //     }
    //     return ans;
    // }





    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        vector<ll> prefix(nums.size(),-1),suffix(nums.size(),-1);
        ll n=nums.size()/3;

        priority_queue<int>pq;
        ll sum=0;
        for(int i=0;i<nums.size();i++){
             sum+=nums[i];
             pq.push(nums[i]);
             if(pq.size()>n){
                 sum-=pq.top();
                 pq.pop();
             }
             if(pq.size()==n){
                prefix[i]=sum;
             }
        }


        priority_queue<int,vector<int>,greater<>>pq1;
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
             sum+=nums[i];
             pq1.push(nums[i]);
             if(pq1.size()>n){
                 sum-=pq1.top();
                 pq1.pop();
             }
             if(pq1.size()==n){
                suffix[i]=sum;
             }
        }


       ll ans=LLONG_MAX;
       for(int i=n-1;i<2*n;i++){
           ans=min(ans,prefix[i]-suffix[i+1]);
       }
       return ans;
    }
};