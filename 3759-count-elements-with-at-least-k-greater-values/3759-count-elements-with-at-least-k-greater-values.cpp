class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     int j=i;
        //     while(j<nums.size()&&nums[j]==nums[i]){
        //         j++;
        //     }
        //     if(nums.size()-j>=k)
        //     ans+=j-i;
        //     i=j-1;
        // }
        // return ans;


        // sort(nums.begin(),nums.end());
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     int idx=upper_bound(nums.begin()+i,nums.end(),nums[i])-nums.begin();
        //     if(nums.size()-idx>=k){
        //         ans+=idx-i;
        //     }
        //     i=idx-1;
        // }
        // return ans;



        // if(k==0) return nums.size();
        // priority_queue<int>pq;
        // for(int i=0;i<nums.size();i++){
        //     pq.push(nums[i]);
        // }
        // k--;
        // while(!pq.empty()&&(k-->0)){
        //     pq.pop();
        // }
        // int num=pq.top();
        // while(!pq.empty()&&num==pq.top()){
        //     pq.pop();
        // }
        // return pq.size();

        if(k==0) return nums.size();
        sort(nums.begin(),nums.end());
        int idx=nums.size()-k;
        int num=nums[idx];
        while(idx>=0&&num==nums[idx]) idx--;
        return idx+1;
    }
};