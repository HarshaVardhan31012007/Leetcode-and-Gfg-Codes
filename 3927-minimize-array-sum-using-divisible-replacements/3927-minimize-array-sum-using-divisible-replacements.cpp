class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int maxi=*max_element(nums.begin(),nums.end());
        // unordered_set<int>st;
        // unordered_map<int,vector<int>>mpp;
        // for(int i=0;i<nums.size();i++)
        // mpp[nums[i]].push_back(i);
        // for(int i=0;i<nums.size();i++){
        //     if(st.count(nums[i])) continue;
        //     for(int j=nums[i];j<=maxi;j+=nums[i]){
        //         if(!mpp.count(j)) continue;
        //         for(auto &idx:mpp[j]){
        //             nums[idx]=nums[i];
        //         }
        //         mpp[j].clear();
        //         mpp.erase(j);
        //     }
        //     st.insert(nums[i]);
        // }
        // long long ans=0;
        // for(auto &each:nums)
        //     ans+=each;
        // return ans;

        sort(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>best(maxi+1,-1);
        for(int i=0;i<nums.size();i++){
            if(best[nums[i]]!=-1) continue; 
            for(int j=nums[i];j<=maxi;j+=nums[i]){
                if(best[j]==-1)
                best[j]=nums[i];
            }
        }
        for(int i=0;i<=maxi;i++){
            if(best[i]==-1)
            best[i]=i;
        }
        long long ans=0;
        for(auto &each:nums)
            ans+=best[each];
        return ans;
        
    }
};