class Solution {
public:
    // long long maxSumTrionic(vector<int>& nums) {
    //     int n=nums.size();
    //     int j=0;long long int ans=LLONG_MIN;
    //     long long int temp=0;
    //     while(j<n){
    //         bool flag1=false,flag2=false,flag3=false;
    //         long long int sum=temp;
    //         if(temp!=0){
    //             flag1=true;
    //         }
    //         else{
    //             sum=nums[j];
    //         }
    //         if(!flag1){
    //             while(j+1<n&&nums[j]<nums[j+1]){
    //                 flag1=true;
    //                 sum+=nums[j+1];
    //                 if(j>0&&nums[j-1]<nums[j]&&nums[j-1]<0){
    //                     sum-=nums[j-1];
    //                 }
    //                 j++;
    //             }
    //         }
    //         while(flag1&&j+1<n&&nums[j]>nums[j+1]){
    //             flag2=true;
    //             sum+=nums[j+1];
    //             j++;
    //         }
    //         temp=nums[j];
    //         while(flag1&&flag2&&j+1<n&&nums[j]<nums[j+1]){
    //             flag3=true;
    //             sum+=nums[j+1];
    //             temp+=nums[j+1];
    //             if(j>0&&nums[j-1]<nums[j]&&nums[j-1]<0){
    //                 temp-=nums[j-1];
    //             }
    //             cout<<sum<<endl;
    //             ans=max(ans,sum);
    //             j++;
    //         }
    //         if(!flag1){
    //            j++;
    //         }
    //         int cond=flag1&&flag2&&flag3;
    //         if(!cond){
    //             temp=0;
    //         }
    //     }
    //     return ans;
    // }


 
    long long solve(vector<int>&nums,int i,int trend,vector<vector<long long int>>&dp){
        if(i>=nums.size()){
            if(trend==3)
            return 0;
            else
            return LLONG_MIN/2;
        }
        if(dp[i][trend]!=LLONG_MIN) return dp[i][trend];
        long long skip=LLONG_MIN/2;
        long long take=LLONG_MIN/2;
        if(trend==0){
            skip=solve(nums,i+1,0,dp);
        }
        if(trend==3)
        take=nums[i];
        if(i+1<nums.size()){
            int curr=nums[i];
            int next=nums[i+1];
            if(trend==0&&next>curr){
                take=max(take,curr+solve(nums,i+1,1,dp));
            }
            else if(trend==1){
                if(next>curr){
                    take=max(take,curr+solve(nums,i+1,1,dp));
                }
                else if(next<curr){
                    take=max(take,curr+solve(nums,i+1,2,dp));
                }
            }
            else if(trend==2){
                if(next>curr){
                    take=max(take,curr+solve(nums,i+1,3,dp));
                }
                else if(next<curr){
                    take=max(take,curr+solve(nums,i+1,2,dp));
                }
            }
            else if(trend==3&&next>curr){
                take=max(take,curr+solve(nums,i+1,3,dp));
            }
        }
        return dp[i][trend]=max(take,skip);
    }
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long int>>dp(n+1,vector<long long int>(4,LLONG_MIN));
        return solve(nums,0,0,dp);
    }
};