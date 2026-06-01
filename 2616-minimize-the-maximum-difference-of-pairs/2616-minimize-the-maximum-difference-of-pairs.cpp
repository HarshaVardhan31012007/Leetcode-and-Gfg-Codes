class Solution {
public:
    // void func(vector<int>&nums,int p,int &ans,int i){
    //     int n=nums.size();
    //     int count=p;
    //     deque<int>dq;
    //     while(count>0&&i<n-1){
    //         while(!dq.empty()&&(nums[dq.back()+1]-nums[dq.back()])<=(nums[i+1]-nums[i])){
    //             dq.pop_back();
    //         }
    //         dq.push_back(i);
    //         count--;
    //         i+=2;
    //     }
    //     if(count!=0) return;
    //     ans=min(ans,nums[dq.front()+1]-nums[dq.front()]);
    //     for(int j=i;j<n-1;j+=2){
    //         if(!dq.empty()&&(dq.front()<(j-(2*p-1)))){
    //             dq.pop_front();
    //         }
    //         while(!dq.empty()&&(nums[dq.back()+1]-nums[dq.back()])<=(nums[i+1]-nums[i])){
    //             dq.pop_back();
    //         }
    //         dq.push_back(i);
    //         ans=min(ans,nums[dq.front()+1]-nums[dq.front()]);
    //     }
    // }
    // int minimizeMax(vector<int>& nums, int p) {
    //     if(p==0) return 0;
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     int ans=INT_MAX;
    //     func(nums,p,ans,0);
    //     func(nums,p,ans,1);
    //     return ans;
    // }



    bool possible(vector<int>&nums,int mid,int p){
        int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++){
            if((nums[i]-nums[i-1])<=mid){
                count++;
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int s=INT_MAX;
        int e=0;
        for(int i=0;i<n-1;i++){
            s=min(s,nums[i+1]-nums[i]);
            e=max(e,nums[i+1]-nums[i]);
        }
        int ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(nums,mid,p)){
                 ans=mid;
                 e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};