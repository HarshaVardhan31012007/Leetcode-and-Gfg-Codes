class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0;
        int j=k-1;
        double sum=0;
            for(int y=i;y<=j;y++)
            sum=sum+arr[y];
            double ans=sum;
            j++;
            while(j<n){
            sum=sum-arr[i++];
            sum=sum+arr[j++];
            ans=max(ans,sum);
            }
         double average=ans/k;
        return average;
    }
};