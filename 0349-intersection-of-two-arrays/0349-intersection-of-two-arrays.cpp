class Solution {
public:
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int>ans;
    //     for(int i=0;i<nums1.size();i++){
    //         for(int j=0;j<nums2.size();j++){
    //             if(nums1[i]==nums2[j]){
    //                 ans.push_back(nums1[i]);
    //             }
    //         }
    //     }
      // sort(ans.begin(),ans.end());
       // ans.erase(unique(ans.begin(),ans.end()),ans.end());

    //     return ans;
    // }



    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int m=nums1.size();
        int n=nums2.size();
        int i=0;
        int j=0;
        int las=-1;
        while(i<m&&j<n){
            if(nums1[i]==nums2[j]){
                if(las!=nums1[i]){
                ans.push_back(nums1[i]);
                las=nums1[i];
                }
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            i++;
            else if(nums1[i]>nums2[j])
            j++;
        }
       // ans.erase(unique(ans.begin(),ans.end()),ans.end());//instead of this at starting point use set datastructure and convert into vector
        return ans;
    }


        // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>ans;
        // unordered_map<int,int>mpp;
        // for(int i=0;i<nums1.size();i++){
        //     mpp[nums1[i]]++;
        // }
        // for(int j=0;j<nums2.size();j++){
        // auto it=mpp.find(nums2[j]);
        // if(it!=mpp.end()&&it->second>0){
        //     ans.push_back(nums2[j]);
        //    // mpp[nums2[j]]=0;
        //    mpp.erase(nums2[j]);
        // }
        // }
        // return ans;
        //}
};