class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;int j=0;
        int ans1=0;int ans2=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans1++;ans2++;i++;j++;
              while(i<nums1.size()&&nums1[i]==nums1[i-1]){
                ans1++;i++;
              }
              while(j<nums2.size()&&nums2[j]==nums2[j-1]){
                ans2++;j++;
              }
            }
            else if(nums1[i]<nums2[j])
            i++;
            else
            j++;
        }
        return {ans1,ans2};
    }
};