class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int i=0;
        int j=0;
        set<pair<int,int>>st;
        int ans=1;
        while(j<n){
            st.insert({nums[j],j});
            auto it=st.end();it--;
            int maxi=it->first;
            int mini=st.begin()->first;
            if((maxi-mini)>limit){
                st.erase({nums[i],i});
                i++;
                it=st.end();it--;
                maxi=it->first;
                mini=st.begin()->first;
            }
            if((maxi-mini)<=limit)
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};