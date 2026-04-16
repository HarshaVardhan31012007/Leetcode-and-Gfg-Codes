class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // unordered_map<int,int>mpp;
        // int n=nums.size();
        // vector<int>ans(n,-1);
        // for(int i=0;i<2*n;i++){
        //     if(i>=n&&mpp.count(nums[i%n])&&(i%n)!=((mpp[nums[i%n]])%n)){
        //         if(ans[i%n]==-1)
        //         ans[i%n]=i-mpp[nums[i%n]];
        //         else
        //         ans[i%n]=min(ans[i%n],i-mpp[nums[i%n]]);
        //     }
        //     mpp[nums[i%n]]=i;
        // }
        // mpp.clear();
        // for(int i=2*n-1;i>=0;i--){
        //     if(i<n&&mpp.count(nums[i%n])&&(i%n)!=(mpp[nums[i%n]]%n)){
        //         if(ans[i%n]==-1)
        //         ans[i%n]=mpp[i%n]-i;
        //         else
        //         ans[i%n]=min(ans[i%n],mpp[nums[i%n]]-i);
        //     }
        //     mpp[nums[i%n]]=i;
        // }

        // vector<int>ans1;
        // for(auto &each:queries){
        //     int currans=(ans[each]==0?-1:ans[each]);
        //     ans1.push_back(currans);
        // }
        // return ans1;



       int n=nums.size();
       unordered_map<int,vector<int>>mpp;
       for(int i=0;i<n;i++){
          mpp[nums[i]].push_back(i);
       }
       vector<int>ans;
       for(auto &each:queries){
           vector<int>&vec=mpp[nums[each]];
           int size=vec.size();
           if(size==1){
             ans.push_back(-1);
             continue;
           }
           int idx=lower_bound(vec.begin(),vec.end(),each)-vec.begin();
           int curr=vec[idx];
           int left=vec[(idx-1+size)%size];
           int right=vec[(idx+1)%size];
           int leftmin=min(abs(curr-left),n-abs(curr-left));
           int rightmin=min(abs(curr-right),n-abs(curr-right));
           ans.push_back(min(leftmin,rightmin));
       } 
       return ans;
    }
};