// User function template for C++

class Solution {
  public:
    bool possible(vector<int>&arr,int k,int mid){
        int sum=0;int c=1;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=mid)
            sum+=arr[i];
            else{
                c++;
                if(c>k) return false;
                sum=arr[i];
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
       int s=*max_element(arr.begin(),arr.end());
       int e=accumulate(arr.begin(),arr.end(),0);
       int ans=-1;
       while(s<=e){
           int mid=s+(e-s)/2;
           if(possible(arr,k,mid)){
               ans=mid;
               e=mid-1;
           }
           else
           s=mid+1;
       }
       return ans;
    }
};