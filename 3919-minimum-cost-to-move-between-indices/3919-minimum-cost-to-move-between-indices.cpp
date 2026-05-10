class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=0;
        suffix[n-1]=0;
        vector<int>closest(n);
        closest[0]=1;closest[n-1]=n-2;
        for(int i=1;i<n-1;i++){
           int diff=abs(nums[i]-nums[i-1]);
           closest[i]=(i-1);
           if(abs(nums[i]-nums[i+1])<diff)
           closest[i]=(i+1);
        }
        int sum=0;
        for(int i=1;i<n;i++){
            int curr=abs(nums[i]-nums[i-1]);
            if(closest[i-1]==i){
                curr=min(curr,1);
            }
            sum+=curr;
            prefix[i]=sum;
        }
        sum=0;
        for(int i=n-2;i>=0;i--){
            int curr=abs(nums[i]-nums[i+1]);
            if(closest[i+1]==i){
                curr=min(curr,1);
            }
            sum+=curr;
            suffix[i]=sum;
        }
        vector<int>ans;
        for(auto &each:queries){
            int x=each[0];int y=each[1];
            if(x<=y){
              ans.push_back(prefix[y]-prefix[x]);
            }
            else
            ans.push_back(suffix[y]-suffix[x]);
        }
        return ans;
    }
};