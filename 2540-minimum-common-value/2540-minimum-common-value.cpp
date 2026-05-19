class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // int i=0;int j=0;
        // while(i<nums1.size()&&j<nums2.size()){
        //     if(nums1[i]<nums2[j]){
        //        i++;
        //     }
        //     else if(nums1[i]>nums2[j]){
        //        j++;
        //     }
        //     else
        //     return nums1[i];
        // }
        // return -1;


        // unordered_set<int>st(nums2.begin(),nums2.end());
        // for(auto &each:nums1){
        //     if(st.count(each)){
        //         return each;
        //     }
        // }
        // return -1;


        
        for(auto &each:nums1){
            if(binary_search(nums2.begin(),nums2.end(),each)){
                return each;
            }
        }
        return -1;
    }
};