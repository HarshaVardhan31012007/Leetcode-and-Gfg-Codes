class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int sum=0;
        unordered_map<int,int>mpp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0)
            ans=max(ans,i+1);
            if(mpp.count(sum)){
                ans=max(ans,i-mpp[sum]);
            }
            else
            mpp[sum]=i;
        }
        return ans;
    }
};