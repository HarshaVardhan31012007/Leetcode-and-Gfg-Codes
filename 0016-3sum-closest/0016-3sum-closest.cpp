class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
         int n=arr.size();
         int mini=INT_MAX;int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i>0&&arr[i]==arr[i-1]) continue;
           int j=i+1;
           int k=n-1;
           while(j<k){
            long int sum=arr[i]+arr[j]+arr[k];
            if(sum<target){
            if(abs(sum-target)<mini){
             mini=abs(sum-target);
             ans=sum;
            }
            j++;
            }
            else if(sum>target){
            if(abs(sum-target)<mini){
             mini=abs(sum-target);
             ans=sum;
            }
            k--;
            }
            else{
               return sum;
            }
           }
        }
        return ans;
    }
};