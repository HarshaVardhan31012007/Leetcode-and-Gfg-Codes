class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int arr[100]={0};
        for(auto &each:nums){
            maxi=max(maxi,each);
            mini=min(mini,each);
            arr[each-1]=1;
        }
        vector<int>ans;
        for(int i=mini+1;i<maxi;i++){
            if(arr[i-1]==0)
            ans.push_back(i);
        }
        return ans;
    }
};