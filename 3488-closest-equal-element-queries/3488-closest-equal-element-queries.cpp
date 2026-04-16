class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<2*n;i++){
            if(i>=n&&mpp.count(nums[i%n])&&(i%n)!=((mpp[nums[i%n]])%n)){
                if(ans[i%n]==-1)
                ans[i%n]=i-mpp[nums[i%n]];
                else
                ans[i%n]=min(ans[i%n],i-mpp[nums[i%n]]);
            }
            mpp[nums[i%n]]=i;
        }
        mpp.clear();
        for(int i=2*n-1;i>=0;i--){
            if(i<n&&mpp.count(nums[i%n])&&(i%n)!=(mpp[nums[i%n]]%n)){
                if(ans[i%n]==-1)
                ans[i%n]=mpp[i%n]-i;
                else
                ans[i%n]=min(ans[i%n],mpp[nums[i%n]]-i);
            }
            mpp[nums[i%n]]=i;
        }

        vector<int>ans1;
        for(auto &each:queries){
            int currans=(ans[each]==0?-1:ans[each]);
            ans1.push_back(currans);
        }
        return ans1;
    }
};