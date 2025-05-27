class Solution {
  public:
    bool possible(vector<int>&arr,int mid,int k,int total){
        int c=1;int sum=0;
        for(int i=0;i<arr.size();i++){
        if(arr[i]>mid) return false;
           sum=sum+arr[i];
           if(sum>mid){
               sum=arr[i];
               c++;
           }
        }
        return c<=k;
    }
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size()) return -1;
        int total=accumulate(arr.begin(),arr.end(),0);
        int s=*min_element(arr.begin(),arr.end());
        int e=total;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(arr,mid,k,total)){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};