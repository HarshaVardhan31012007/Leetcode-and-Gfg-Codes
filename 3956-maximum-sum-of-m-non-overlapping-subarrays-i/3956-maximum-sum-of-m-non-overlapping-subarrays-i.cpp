class Solution {
public:
    // bool possible(vector<int>&nums,int m,int l,int r,long long mid){
    //     int n=nums.size();
    //     int start=0;
    //     long long sum=0;
    //     for(int i=0;i<n;i++){
    //         if((i-start+1)>=l&&(i-start+1)<=&&sum+nums[i]<=mid)
    //         sum+=nums[i];
    //         else if((i-start+1)>r){
                
    //         }
    //         if(sum>mid){
    //             start=i+1;
    //             sum=0;
    //             m--;
    //         }
    //     }
    //     return 
    // }
    // long long maximumSum(vector<int>& nums, int m, int l, int r) {
    //     long long mini=0;
    //     long long maxi=0;
    //     long long sum1=0;
    //     long long sum2=0;
    //     for(auto &each:nums){
    //         sum1+=each;
    //         sum2+=each;
    //         mini=min(mini,sum1);
    //         maxi=max(maxi,sum2);
    //         if(sum1>0) sum1=0;
    //         if(sum2<0) sum2=0;
    //     }
    //     long long ans;
    //     while(mini<=maxi){
    //         long long mid=mini+(maxi-mini)/2;
    //          if(possible(nums,m,l,r,mid)){
    //              ans=mid;
    //              s=mid+1;
    //          }
    //          else{
    //              e=mid-1;
    //          }
    //     }
    //     return ans;
    // }



    
    
    // long long find(vector<int>&nums,int i,int m,int l,int r){
    //     if(m<0) return LLONG_MIN;
    //     if(i>=n&&m>=0&&m!=m1) return 0;
    //     if(i>=n&&m==m1) return LLONG_MIN;
    //     if(dp[i][m]!=-1) return dp[i][m];
    //     long long ans=LLONG_MIN;
    //     for(int j=(i+l-1);j<=min(n-1,(i+r-1));j++){
    //         long long rec=find(nums,j+1,m-1,l,r);
    //         if(rec!=LLONG_MIN)
    //         ans=max(ans,prefix[j+1]-prefix[i]+rec);
    //     }
    //     ans=max(ans,find(nums,i+1,m,l,r));
    //     return dp[i][m]=ans;
    // }
    vector<long long>prefix;
    int n;int m1;
    vector<vector<long long>>dp;
    long long maximumSum(vector<int>& nums, int m2, int l, int r) {
        n=nums.size();m1=m2;
        prefix.assign(n+1,0);
        dp.assign(m1+1,vector<long long>(n+1,LLONG_MIN));
        for(int i=1;i<=n;i++){
            prefix[i]+=prefix[i-1]+nums[i-1];
        }
        for(int m=0;m<m1;m++)
        dp[m][n]=0;
        for(int i=0;i<=n;i++)
        dp[0][i]=0;
        for(int m=1;m<=m1;m++){
            vector<long long>temp(dp[m-1]);
            for(int i=n;i>=0;i--){
                temp[i]+=prefix[i];
            }
            deque<int>dq;
            int low=n+l-2;int high=min(n-1,n+r-2);
            for(int j=high;j>=low;j--){
                while(!dq.empty()&&temp[dq.front()]<=temp[j+1]){
                    dq.pop_front();
                }
                dq.push_front(j+1);
            }
            if(!dq.empty()){
               dp[m][n-1]=max(dp[m][n-1],temp[dq.back()]-prefix[n-1]);
            }
            dp[m][n-1]=max(dp[m][n-1],dp[m][n]);
            for(int i=n-2;i>=0;i--){
                if(!dq.empty()&&dq.back()>(i+r)) dq.pop_back();
                if(i+l<=n){
                    while(!dq.empty()&&temp[dq.front()]<=temp[i+l]){
                        dq.pop_front();
                    }
                    dq.push_front(i+l);
                    dp[m][i]=max(dp[m][i],temp[dq.back()]-prefix[i]);
                }
                dp[m][i]=max(dp[m][i],dp[m][i+1]);
            }
        }
        return dp[m1][0];
    }
};