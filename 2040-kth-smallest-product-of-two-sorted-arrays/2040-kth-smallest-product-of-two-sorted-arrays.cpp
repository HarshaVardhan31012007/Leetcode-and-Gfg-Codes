class Solution {
public:
    long long countp(vector<int>&nums2,long long x1,long long res){
        int left=0;
        int right=nums2.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            long long prod=x1*nums2[mid];
            if(x1>=0&&prod<=res||x1<0&&prod>res){
                left=mid+1;
            }
            else
            right=mid-1;
        }
        if(x1>=0)
        return left;
        return nums2.size()-left;
    }
    long long count(vector<int>& nums1, vector<int>& nums2, long long res){
        if(nums1.size()>nums2.size()) return count(nums2,nums1,res);
        long long total=0;
        for(int i=0;i<nums1.size();i++){
            total+=countp(nums2,nums1[i],res);
        }
        return total;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long s=-1e10;long long e=1e10;
        long long ans=-1;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(count(nums1,nums2,mid)>=k){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};