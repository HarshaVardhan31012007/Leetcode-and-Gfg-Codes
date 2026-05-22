class Solution {
public:
    int merge(vector<int>&nums,int s,int mid,int e){
        vector<int>temp(e-s+1);
        int i=s;int j=mid+1;int k=0;
        int c=0;
        while(i<=mid&&j<=e){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=e){
            temp[k++]=nums[j++];
        }
        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
        return c;
    }
    int countPairs(vector<int>&nums,int s,int mid,int e){
        int left=mid;
        int c=0;
        for(int right=e;right>mid;right--){
             while(left>=s&&nums[left]>2LL*nums[right]){
                left--;
             }
             c+=(mid-left);
        }
        return c;
    }
    int mergeSort(vector<int>&nums,int s,int e){
        if(s==e) return 0;
        int mid=s+(e-s)/2;
        int c=0;
        c+=mergeSort(nums,s,mid);
        c+=mergeSort(nums,mid+1,e);
        c+=countPairs(nums,s,mid,e);
        merge(nums,s,mid,e);
        return c;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int ans=mergeSort(nums,0,n-1);
        return ans;
    }
};