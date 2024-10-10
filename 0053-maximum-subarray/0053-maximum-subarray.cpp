class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L > R) return INT_MIN;
        int mid = (L + R) / 2, leftSum = 0, rightSum = 0;int sum1=0;
        for(int i=mid-1;i>=L;i--){
            sum1 += A[i];
            leftSum=max(leftSum, sum1);
            }
            int sum2=0;
        for(int i = mid+1; i <= R; i++){
            sum2 += A[i];
            rightSum = max(rightSum, sum2); 
            }
       return max({maxSubArray(A, L, mid-1), maxSubArray(A, mid+1, R), leftSum + A[mid] + rightSum} );
    }	
    	
};