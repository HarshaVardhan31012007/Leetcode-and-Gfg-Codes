class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;
        }
        for(int j=0;j<nums2.size();j++){
        auto it=mpp.find(nums2[j]);
        if(it!=mpp.end()&&it->second>0){
            ans.push_back(nums2[j]);
            mpp[nums2[j]]--;
        }
        }
        return ans;
    }
};