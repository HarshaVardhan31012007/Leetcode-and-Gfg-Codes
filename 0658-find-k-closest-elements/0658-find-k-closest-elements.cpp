class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // int n=arr.size();
        // int i=0;
        // int j=n-1;
        // while((j-i+1)>k){
        //     if(abs(arr[i]-x)<=abs(arr[j]-x)){
        //         j--;
        //     }
        //     else if(abs(arr[i]-x)>abs(arr[j]-x)){
        //         i++;
        //     }
        // }
        // vector<int>ans;
        // for(int k=i;k<=j;k++){
        //     ans.push_back(arr[k]);
        // }
        // return ans;



        int n=arr.size();
        int idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i=idx-1;int j=idx;
        vector<int>ans;
        while((j-i-1)<k){
            if(i==-1){
                j++;
            }
            else if(j==n){
                i--;
            }
            else if(abs(arr[i]-x)<=abs(arr[j]-x)){
                i--;
            }
            else{
                j++;
            }
        }
        for(int k=i+1;k<j;k++){
            ans.push_back(arr[k]);
        }
        return ans;
    }
};