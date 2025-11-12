class Solution {
public:
    // int fgcd(int x,int y){
    //     while(x){
    //         int r=y%x;
    //         y=x;
    //         x=r;
    //     }
    //     return y;
    // }
    // int minOperations(vector<int>& nums) {
    //     int x=nums[0];
    //     int y=nums[1];
    //     int c=0;
    //     int gcd=fgcd(x,y);
    //     if(x==1) c++;
    //     if(y==1) c++;
    //     for(int i=2;i<nums.size();i++){
    //         if(nums[i]==1) c++;
    //         gcd=fgcd(gcd,nums[i]);
    //     }
    //     if(c>0) return nums.size()-c;
    //     if(gcd!=1) return -1;
    //     int ans=0;
    //     int n=nums.size();
    //     while(n>1){
    //         for(int i=0;i<n-1;i++){
    //             int ans=fgcd(nums[i],nums[i+1]);
    //             if(ans==1){
    //                  return n+((int)nums.size()-n)*2;
    //             }
    //             nums[i]=ans;
    //         }
    //         n--;
    //     }
    //     return -1;
    // }




    
    // int minOperations(vector<int>& nums) {
    //     int x=nums[0];
    //     int y=nums[1];
    //     int c=0;
    //     int gcd=__gcd(x,y);
    //     if(x==1) c++;
    //     if(y==1) c++;
    //     for(int i=2;i<nums.size();i++){
    //         if(nums[i]==1) c++;
    //         gcd=__gcd(gcd,nums[i]);
    //     }
    //     if(c>0) return nums.size()-c;
    //     if(gcd!=1) return -1;
    //     int n=nums.size();
    //     while(n>1){
    //         for(int i=0;i<n-1;i++){
    //             int ans=__gcd(nums[i],nums[i+1]);
    //             if(ans==1){
    //                  return n+((int)nums.size()-n)*2;
    //             }
    //             nums[i]=ans;
    //         }
    //         n--;
    //     }
    //     return -1;
    // }



     int minOperations(vector<int>& nums) {
        int c=0;
        for(auto &num:nums){
            if(num==1)
            c++;
        }
        if(c>0) return nums.size()-c;
        int n=nums.size();
        while(n>1){
            for(int i=0;i<n-1;i++){
                int ans=__gcd(nums[i],nums[i+1]);
                if(ans==1){
                     return n+((int)nums.size()-n)*2;
                }
                nums[i]=ans;
            }
            n--;
        }
        return -1;
    }
};