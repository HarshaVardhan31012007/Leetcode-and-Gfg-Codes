class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        // auto it=max_element(arr.begin(),arr.end());
        // int ans=*it;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]==ans)
        //     return i;
        // }
        // return -1;

        // int maxAns=INT_MIN;
        // int maxIndex=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>maxAns){
        //         maxAns=nums[i];
        //         maxIndex=i;
        //     }
        // }
        // return maxIndex;


        // int s=0;
        // int e=nums.size()-1;
        // int ans=-1;
        // while(s<=e){
        //     int mid=s+(e-s)/2;
        //     if(nums[mid]>nums[mid+1]){
        //         ans=mid;
        //         e=mid-1;
        //     }
        //     else{
        //         s=mid+1;
        //     }
        // }
        // return ans;


         int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[mid+1]){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return s;

        
       //mid==0 is imp like for 3 5 3 2 0
        // int s=0;
        // int e=nums.size()-1;
        // int ans=-1;
        // while(s<=e){
        //     int mid=s+(e-s)/2;
        //     if(mid==0||nums[mid-1]<nums[mid]){
        //         ans=mid;
        //         s=mid+1;
        //     }
        //     else{
        //         e=mid-1;
        //     }
        // }
        // return ans;
    }
};