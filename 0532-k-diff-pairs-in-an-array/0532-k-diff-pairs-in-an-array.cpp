class Solution {
public:
    // int bs(vector<int>&nums,int s,int e,int t){
    //     while(s<=e){
    //         int mid=s+(e-s)/2;
    //         if(nums[mid]==t)
    //         return mid;
    //         else if(nums[mid]<t)
    //         s=mid+1;
    //         else
    //         e=mid-1;
    //     }
    //     return -1;
    // }
    int findPairs(vector<int>& nums, int k) {
    //    sort(nums.begin(),nums.end());
    //    unordered_map<int,int>mpp;int ans=0;
    //    for(int i=0;i<nums.size();i++){
    //     int t=nums[i]-k;
    //     if((mpp.count(nums[i])==0||k==0)&&mpp.find(t)!=mpp.end()){
    //         if(k==0){
    //             if(mpp[t]==1)
    //             ans++;
    //         }
    //         else
    //         ans++;
    //     }
    //     mpp[nums[i]]++;
    //    } 
    //    return ans;


        // sort(nums.begin(),nums.end());
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(abs(nums[j]-nums[i])==k){
        //             if((i-1>=0&&nums[i-1]==nums[i])||(j-1>=0&&j!=i+1&&nums[j]==nums[j-1]))
        //             continue;
        //             else
        //             ans++;
        //         }
        //     }
        // }
        // return ans;



        // sort(nums.begin(),nums.end());
        // int i=0;
        // int j=1;
        // set<pair<int,int>>ans;
        // while(j<nums.size()){
        //     int diff=nums[j]-nums[i];
        //     if(diff==k){
        //         ans.insert({nums[i++],nums[j++]});
        //     }
        //     else if(diff>k){
        //         i++;
        //     }
        //     else
        //     j++;
        //     if(i==j) j++;
        // }
        // return ans.size();



        // sort(nums.begin(),nums.end());
        // set<pair<int,int>>ans;
        // for(int i=0;i<nums.size();i++){
        //     if(bs(nums,i+1,nums.size()-1,nums[i]+k)!=-1)
        //     ans.insert({nums[i],nums[i]+k});
        // }
        // return ans.size();


        
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            if(binary_search(nums.begin()+i+1,nums.end(),nums[i]+k))
            ans.insert({nums[i],nums[i]+k});
        }
        return ans.size();
    }
};