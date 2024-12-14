class Solution {
public:
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int>ans;
    //      sort(nums1.begin(),nums1.end());
    //      sort(nums2.begin(),nums2.end());
    //     for(int i=0;i<nums1.size();i++){
    //         if(i+1<nums1.size()&&nums1[i]==nums1[i+1])
    //         continue;
    //         for(int j=0;j<nums2.size();j++){
    //              if(j+1<nums2.size()&&nums2[j]==nums2[j+1])
    //               continue;
    //            if(nums1[i]<nums2[j]) break;
    //             if(nums1[i]==nums2[j]){
    //                 ans.push_back(nums1[i]);
    //             }
    //         }
    //     }
    //    sort(ans.begin(),ans.end());
    //    ans.erase(unique(ans.begin(),ans.end()),ans.end());

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

        //1
        // int las=-1;
        while(i<m&&j<n){
            if(nums1[i]==nums2[j]){
               // if(las!=nums1[i]){ 
                if(ans.size()==0||ans.back()!=nums1[i]){
                ans.push_back(nums1[i]);
               // las=nums1[i];
                }
                i++;
                j++;
            }

        //2
        // while(i<m&&j<n){
        //     if(nums1[i]==nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //         j++;
        //     }

        //3 without using any function for avoiding duplicates
          //  while(i<m&&j<n){

            // if((i>0)&&(nums1[i]==nums1[i-1])){//first only should be condition i>)
            //     i++;
            //     continue;
            // }
        //     if((i+1<m)&&(nums1[i]==nums1[i+1])){
        //         i++;
        //         continue;
        //     }
        //     if(nums1[i]==nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //         j++;
        //     }
            else if(nums1[i]<nums2[j])
            i++;
            else if(nums1[i]>nums2[j])
            j++;
        }
    //for 2   // ans.erase(unique(ans.begin(),ans.end()),ans.end());//instead of this at starting point use set datastructure and convert into vector
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
        // }
};