class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // int n=cardPoints.size();
        // int len=n-k;
        // int total=0;
        // int minSum=INT_MAX;
        // int sum=0;
        // for(int i=0;i<len;i++){
        //     sum+=cardPoints[i];
        //     total+=cardPoints[i];
        // }
        // minSum=min(minSum,sum);
        // for(int k=len;k<n;k++){
        //     sum-=cardPoints[k-len];
        //     sum+=cardPoints[k];
        //     minSum=min(minSum,sum);
        //     total+=cardPoints[k];
        // }
        // return total-minSum;



        int n=cardPoints.size();
        int sum=0;
        int i=0;
        for(;i<k;i++)
        sum+=cardPoints[i];
        int maxSum=sum;
        i--;
        int j=n-1;
        while(j>=n-k){
            sum-=cardPoints[i--];
            sum+=cardPoints[j--];
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};