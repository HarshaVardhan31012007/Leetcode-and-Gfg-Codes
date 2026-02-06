class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        int j=0;long long int ans=LLONG_MIN;
        long long int temp=0;
        while(j<n){
            bool flag1=false,flag2=false,flag3=false;
            long long int sum=temp;
            if(temp!=0){
                flag1=true;
            }
            else{
                sum=nums[j];
            }
            if(!flag1){
                while(j+1<n&&nums[j]<nums[j+1]){
                    flag1=true;
                    sum+=nums[j+1];
                    if(j>0&&nums[j-1]<nums[j]&&nums[j-1]<0){
                        sum-=nums[j-1];
                    }
                    j++;
                }
            }
            while(flag1&&j+1<n&&nums[j]>nums[j+1]){
                flag2=true;
                sum+=nums[j+1];
                j++;
            }
            temp=nums[j];
            while(flag1&&flag2&&j+1<n&&nums[j]<nums[j+1]){
                flag3=true;
                sum+=nums[j+1];
                temp+=nums[j+1];
                if(j>0&&nums[j-1]<nums[j]&&nums[j-1]<0){
                    temp-=nums[j-1];
                }
                cout<<sum<<endl;
                ans=max(ans,sum);
                j++;
            }
            if(!flag1){
               j++;
            }
            int cond=flag1&&flag2&&flag3;
            if(!cond){
                temp=0;
            }
        }
        return ans;
    }
};