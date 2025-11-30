// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
         unordered_map<int,int>mpp;
         for(int i=0;i<n;i++){
             mpp[arr[i]]=i;
         }
         sort(arr,arr+n);
         for(int i=0;i<n;i++){
             if(abs(mpp[arr[i]]-i)>k) return "No";
         }
         return "Yes"
         ;
    }
};