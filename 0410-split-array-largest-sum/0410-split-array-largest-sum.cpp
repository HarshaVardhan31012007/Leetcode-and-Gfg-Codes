class Solution {
public:
    typedef long long ll;
    bool possible(vector<int>&arr,int mid,int k){
        int n=arr.size();
        ll sum=0;int c=1;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                c++;
                sum=arr[i];
                if(c>k) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        ll s=*max_element(arr.begin(),arr.end());
        ll e=accumulate(arr.begin(),arr.end(),0);
        int ans;
        while(s<=e){
            ll mid=s+(e-s)/2;
            if(possible(arr,mid,k)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};