class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        unordered_set<int>st;
        for(auto &each:nums){
            maxi=max(maxi,each);
            mini=min(mini,each);
            st.insert(each);
        }
        vector<int>ans;
        for(int i=mini+1;i<maxi;i++){
            if(!st.count(i))
            ans.push_back(i);
        }
        return ans;
    }
};