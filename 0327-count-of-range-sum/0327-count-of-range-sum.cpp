class Solution {
public:
    int l,u;
    int merge(vector<long long>&nums,int s,int mid,int e){
        vector<long long>temp(e-s+1);
        int i=s;int j=mid+1;int k=0;int c=0;
        while(i<=mid&&j<=e){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                auto it=lower_bound(nums.begin()+s,nums.begin()+mid+1,1LL*nums[j]-u);
                auto it1=upper_bound(nums.begin()+s,nums.begin()+mid+1,1LL*nums[j]-l);
                if(it1!=nums.begin()+s){
                    it1--;
                    int idx1=it-(nums.begin()+s);
                    int idx2=it1-(nums.begin()+s);
                    if(idx1<=idx2)
                    c+=(idx2-idx1+1);
                }
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=e){
            auto it=lower_bound(nums.begin()+s,nums.begin()+mid+1,1LL*nums[j]-u);
            auto it1=upper_bound(nums.begin()+s,nums.begin()+mid+1,1LL*nums[j]-l);
            if(it1!=nums.begin()+s){
                it1--;
                int idx1=it-(nums.begin()+s);
                int idx2=it1-(nums.begin()+s);
                if(idx1<=idx2)
                c+=(idx2-idx1+1);
            }
            temp[k++]=nums[j++];
        }
        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
        return c;
    }
    int mergeSort(vector<long long>&nums,int s,int e){
        if(s==e) return 0;
        int mid=s+(e-s)/2;
        int c=0;
        c+=mergeSort(nums,s,mid);
        c+=mergeSort(nums,mid+1,e);
        c+=merge(nums,s,mid,e);
        return c;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        l=lower;
        u=upper;
        vector<long long>prefix;
        long long sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix.push_back(sum);
            if(sum>=lower&&sum<=upper){
                ans++;
            }
        }
        ans+=mergeSort(prefix,0,n-1);
        return ans;
    }
};