class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=0;
        if(arr[0]>1){
            arr[0]=1;
            ans++;
        }
        for(int i=1;i<n;i++){
            if((arr[i]-arr[i-1])<=1){
                continue;
            }
            arr[i]=arr[i-1]+1;
            ans++;
        }
        return arr[n-1];
    }
};