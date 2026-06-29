class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // sort(arr.begin(),arr.end());
        // int n=arr.size();
        // int ans=0;
        // if(arr[0]>1){
        //     arr[0]=1;
        //     ans++;
        // }
        // for(int i=1;i<n;i++){
        //     if((arr[i]-arr[i-1])<=1){
        //         continue;
        //     }
        //     arr[i]=arr[i-1]+1;
        //     ans++;
        // }
        // return arr[n-1];


        
        int n=arr.size();
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            freq[min(arr[i],n)]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(freq[i]==0) continue;
             ans=min(ans+freq[i],i);
        }
        return ans;
    }
};