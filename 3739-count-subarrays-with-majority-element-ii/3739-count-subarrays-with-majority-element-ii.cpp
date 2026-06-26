class Solution {
public:
    // long long merge(vector<int>&nums,int s,int mid,int e){
    //     int n=nums.size();
    //     int i=s;int j=mid+1;
    //     int k=0;
    //     long long count=0;
    //     vector<int>temp(e-s+1,0);
    //     while(i<=mid&&j<=e){
    //         if(nums[i]<nums[j]){
    //             temp[k++]=nums[i++];
    //             count+=(e-j+1);
    //         }
    //         else{
    //             temp[k++]=nums[j++];
    //         }
    //     }
    //     while(i<=mid){
    //         temp[k++]=nums[i++];
    //     }
    //     while(j<=e){
    //         temp[k++]=nums[j++];
    //     }
    //     for(int p=s;p<=e;p++){
    //         nums[p]=temp[p-s];
    //     }
    //     return count;
    // }
    // long long countProperPairs(vector<int>&nums,int s,int e){
    //     if(s>=e) return 0;
    //     int mid=s+(e-s)/2;
    //     long long count=0;
    //     count+=countProperPairs(nums,s,mid);
    //     count+=countProperPairs(nums,mid+1,e);
    //     count+=merge(nums,s,mid,e);
    //     return count;
    // }
    // long long countMajoritySubarrays(vector<int>& nums, int target) {
    //     long long ans=0;int sum=0;
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]==target) sum++;
    //         else sum--;
    //         if(sum>0) ans++;
    //         nums[i]=sum;
    //     } 
    //     int n=nums.size();
    //     ans+=countProperPairs(nums,0,n-1);
    //     return ans;
    // }


    
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        mpp[0]=1;
        int cumSum=0;
        int validLeftPoints=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                validLeftPoints+=mpp[cumSum];
                cumSum+=1;
            }
            else{
                cumSum-=1;
                validLeftPoints-=mpp[cumSum];
            }
            mpp[cumSum]+=1;
            ans+=validLeftPoints;
        }
        return ans;
    }
};