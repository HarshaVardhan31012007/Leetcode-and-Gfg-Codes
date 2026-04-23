class Solution {
public:
    #define ll long long
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ans;
        unordered_map<ll,vector<ll>>mpp;
        unordered_map<ll,ll>mpp1;
        for(int i=0;i<n;i++){
            if(!mpp.count(nums[i]))
            mpp[nums[i]].push_back(i);
            else
            mpp[nums[i]].push_back(mpp[nums[i]].back()+i);
            mpp1[i]=(mpp[nums[i]].size()-1);
        }
        for(int i=0;i<n;i++){
            ll pos=mpp1[i];
            ll len=mpp[nums[i]].size();
            ll total=mpp[nums[i]].back();
            ll current=mpp[nums[i]][pos];
            ll left=(1LL*i*(pos+1)-current);
            ll right=((total-current)-1LL*i*(len-(pos+1)));
            ans.push_back(left+right);
        }
        return ans;
    }
}; 