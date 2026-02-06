class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        //its wrong //see greedy wrong//[8,99,65,16,39]
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // int i=0;
        // int j=n-1;
        // while(j-i+1>2){
        //     if(nums[i]*k>=nums[j]){
        //         return n-(j-i+1);
        //     }
        //     int diff=(nums[i+1]*k-nums[j]);
        //     if(diff<(nums[i]*k-nums[j-1])){
        //         j--;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // if((j-i+1)==2){
        //     if(nums[i]*k>=nums[j]){
        //         return n-(j-i+1);
        //     }
        // }
        // return n-1;




        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // int ans=n-1;
        // for(int i=0;i<n;i++){
        //     auto it=upper_bound(nums.begin()+i+1,nums.end(),1LL*nums[i]*k);
        //     if(it!=nums.begin()){
        //         it--;
        //         int size=(it-(nums.begin()+i))+1;
        //         ans=min(ans,n-size);
        //     }
        // }
        // return ans;



        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=INT_MAX;
        while(j<n){
            while(i<j&&nums[j]>1LL*nums[i]*k){
                  i++;
            }
            ans=min(ans,n-(j-i+1));
            j++;
        }
        return ans;
    }
};