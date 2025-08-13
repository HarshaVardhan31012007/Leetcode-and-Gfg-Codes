class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2,vector<int>&temp){
        int i=0;int j=0;int k=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j])
            temp[k++]=nums1[i++];
            else
            temp[k++]=nums2[j++];
        }
        while(i<nums1.size()){
             temp[k++]=nums1[i++];
        }
        while(j<nums2.size()){
             temp[k++]=nums2[j++];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp(nums1.size()+nums2.size(),0);
        merge(nums1,nums2,temp);
        int n=temp.size();
        if(n&1)
        return (double)temp[n/2];
        else
        return (temp[n/2-1]+temp[n/2])/2.0;
    }
};