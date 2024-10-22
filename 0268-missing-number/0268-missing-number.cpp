class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       // for(int i=0;i<nums.size();i++){
       //     if(i==nums[i])
       //     continue;
        //    else
       //     return i;
       // }
int n=nums.size();
int ansIndex=n;
int s=0;
int e=n-1;
while(s<=e){
   int mid=s+(e-s)/2;
   int diff=arr[mid]-mid;
   if(diff==1){
   ans=mid;
   e=mid-1;
}
if(diff==0)
s=mid+1;

}
  
return ans;


        //return nums.size();
    }
};