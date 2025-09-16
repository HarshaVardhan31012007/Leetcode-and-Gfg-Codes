class Solution {
public:
    // void nextGreater(vector<int>& nums2,vector<int>&nextg){
    //      stack<int>s;
    //      s.push(-1);
    //      for(int i=nums2.size()-1;i>=0;i--){
    //         while(!s.empty()&&s.top()!=-1&&s.top()<nums2[i]){
    //             s.pop();
    //         }
    //         nextg.push_back(s.top());
    //         s.push(nums2[i]);
    //      }
    // }
    // int find(vector<int>&nums2,int k){
    //     for(int i=0;i<nums2.size();i++){
    //         if(nums2[i]==k)
    //         return i;
    //     }
    //     return -1;
    // }
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int>nextg;
    //     nextGreater(nums2,nextg);
    //     reverse(nextg.begin(),nextg.end());
    //     vector<int>ans(nums1.size());
    //     for(int i=0;i<nums1.size();i++){
    //         int idx=find(nums2,nums1[i]);
    //         ans[i]=nextg[idx];
    //     }
    //     return ans;
    // }



    // void nextGreater(vector<int>& nums2,vector<int>&nextg){
    //      stack<int>s;
    //      s.push(-1);
    //      for(int i=nums2.size()-1;i>=0;i--){
    //         while(!s.empty()&&s.top()!=-1&&s.top()<nums2[i]){
    //             s.pop();
    //         }
    //         nextg.push_back(s.top());
    //         s.push(nums2[i]);
    //      }
    // }
    // int find(vector<int>&nums2,int k){
    //     for(int i=0;i<nums2.size();i++){
    //         if(nums2[i]==k)
    //         return i;
    //     }
    //     return -1;
    // }
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int>nextg;
    //     nextGreater(nums2,nextg);
    //     vector<int>ans(nums1.size());
    //     for(int i=0;i<nums1.size();i++){
    //         int idx=find(nums2,nums1[i]);
    //         ans[i]=nextg[nextg.size()-1-idx];
    //     }
    //     return ans;
    // }



     void nextGreater(vector<int>& nums2,unordered_map<int,int>&mpp){
         stack<int>s;
         s.push(-1);
         for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty()&&s.top()!=-1&&s.top()<nums2[i]){
                s.pop();
            }
            mpp[nums2[i]]=s.top();
            s.push(nums2[i]);
         }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        nextGreater(nums2,mpp);
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=mpp[nums1[i]];
        }
        return ans;
    }
};