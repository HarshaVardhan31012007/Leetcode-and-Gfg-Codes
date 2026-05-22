class Solution {
public:
    vector<int>ans;
    void merge(vector<pair<int,int>>&nums,int s,int mid,int e){
        vector<pair<int,int>>temp(e-s+1);
        int i=s;int j=mid+1;int k=0;
        while(i<=mid&&j<=e){
            if(nums[i].first<=nums[j].first){
                ans[nums[i].second]+=(j-mid-1);
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid){
            ans[nums[i].second]+=(e-mid);
            temp[k++]=nums[i++];
        }
        while(j<=e){
            temp[k++]=nums[j++];
        }
        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
    }
    void mergeSort(vector<pair<int,int>>&nums,int s,int e){
        if(s==e) return;
        int mid=s+(e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        ans.assign(n,0);
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        mergeSort(v,0,n-1);
        return ans;
    }
};