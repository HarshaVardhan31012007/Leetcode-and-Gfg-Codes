class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0;
        int n=nums.size();
        int e=n-1;
        int ansIndex=-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int diff=nums[mid]-mid;
            if(diff>=1){
                ansIndex=mid;
                e=mid-1;
            }
            else if(diff==0){
                 s=mid+1;
            }
            mid=s+(e-s)/2;
        }
    
    
    if(ansIndex==-1)
            return n;
     return ansIndex;
}
};