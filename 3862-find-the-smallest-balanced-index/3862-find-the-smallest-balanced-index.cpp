class Solution {
public:
    // typedef long long ll;
    // int find(int n){
    //     int c=0;
    //     while(n){
    //         c++;
    //         n=n/10;
    //     }
    //     return c;
    // }
    // int smallestBalancedIndex(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<ll>sum(n,0);
    //     long long temp=0;
    //     for(int i=0;i<n;i++){
    //         sum[i]=temp;
    //         temp+=nums[i];
    //     }
    //     long long p=1LL;
    //     int ans=-1;
    //     long long maxi=1e14;
    //     for(int i=n-1;i>=0;i--){
    //         if(p==sum[i]){
    //             ans=i;
    //         }
    //         int digits1=find(p);
    //         int digits2=find(nums[i]);
    //         if(digits1+digits2>14) break;
    //         p=p*(long long)nums[i];
    //         if(p>maxi) break;
    //     }
    //     return ans;
    // }



    typedef long long ll;
    int find(int n){
        int c=0;
        while(n){
            c++;
            n=n/10;
        }
        return c;
    }
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vector<ll>sum(n,0);
        long long temp=0;
        for(int i=0;i<n;i++){
            sum[i]=temp;
            temp+=nums[i];
        }
        long long p=1LL;
        int ans=-1;
        long long maxi=1e14;
        for(int i=n-1;i>=0;i--){
            if(p==sum[i]){
                ans=i;
            }
            int digits1=find(p);
            int digits2=find(nums[i]);
            if(p>maxi/nums[i]) break;
            p=p*(long long)nums[i];
        }
        return ans;
    }
};