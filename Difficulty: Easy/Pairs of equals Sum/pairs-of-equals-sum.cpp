class Solution {
  public:
    bool findPairs(vector<int>& arr) {
       unordered_map<int,bool>mpp;
       for(int i=0;i<arr.size();i++){
           for(int j=i+1;j<arr.size();j++){
               int sum=arr[i]+arr[j];
               if(mpp.count(sum)==1)
               return true;
               else
               mpp[sum]=1;
           }
       }
       return false;
    }
};