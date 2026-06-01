class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int len=(n1+n2)/2;
        int s=0;
        int e=n1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int mid1=len-mid;
            if((mid==0||mid1==n2||nums1[mid-1]<=nums2[mid1])&&(mid1==0||mid==n1||nums2[mid1-1]<=nums1[mid])){
                if((n1+n2)%2==0) return (max((mid>0?nums1[mid-1]:INT_MIN),(mid1>0?nums2[mid1-1]:INT_MIN))+min((mid==n1?INT_MAX:nums1[mid]),(mid1==n2?INT_MAX:nums2[mid1])))/2.0;
                else
                return min((mid==n1?INT_MAX:nums1[mid]),(mid1==n2?INT_MAX:nums2[mid1]));
            }
            else if(mid>0&&mid1<n2&&nums1[mid-1]>nums2[mid1]){
                e=mid-1;
            }
            else if(mid1>0&&mid<n2&&nums2[mid1-1]>nums1[mid]){
                s=mid+1;
            }
        }
        return -1;
    }
};