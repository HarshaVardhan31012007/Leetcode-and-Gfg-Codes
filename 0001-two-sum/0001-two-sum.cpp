class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>p;
        // int n=nums.size();
        
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target){
        //             p.push_back(i);
        //             p.push_back(j);
        //         }
                
        //     }
    
        // }
        // return p;

        //method 2// if true or false varinat then this is better otherwise space is more
        // vector<int>ans;
        // multimap<int,int>mm;
        // for(int i=0;i<nums.size();i++){
        //     mm.insert({nums[i],i});
        // }
        // sort(nums.begin(),nums.end());
        // int i=0;
        // int j=nums.size()-1;
        // while(i<j){
        //     int sum=nums[i]+nums[j];
        //     if(sum==target){
        //          auto it = mm.begin();
        //          int count=0;
        //  while (it != mm.end()) {
        //    int key = it->first;
        //    if(it->first==nums[i]){
        //     ans.push_back(it->second);
        //     count++;
        //    }
        //     else if(it->first==nums[j]){
        //     ans.push_back(it->second);
        //     count++;
        //    }
        //    if(count==2)
        //    break;
        //    it++;
        //   }
        //        return ans;
        //     }
        //     else if(sum<target)
        //     i++;
        //     else if(sum>target)
        //     j--;
        // }
        // return ans;

        //method 3
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int second=target-num;
            if(mpp.find(second)!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[second]);
            }
            mpp[num]=i;
        
        }
        return ans;
    }

};