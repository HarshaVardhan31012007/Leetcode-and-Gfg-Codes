class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int one=0;
        int zero=0;
        unordered_map<int,int>mpp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1) one++;
            else zero++;
            if(one==zero)
            ans=max(ans,i+1);
            if(mpp.count(one-zero)){
                ans=max(ans,i-mpp[one-zero]);
            }
            else
            mpp[one-zero]=i;
        }
        return ans;
    }
};