class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    //     vector<int>ans;
    //   for(int i=0;i<nums.size();i++){
    //     if(ans.size()==0||ans[0]!=nums[i]){
    //          int count=0;
    //          for(int j=0;j<nums.size();j++){
    //             if(nums[i]==nums[j])
    //             count++;
    //          }
    //          if(count>nums.size()/3)
    //          ans.push_back(nums[i]);
    //          if(ans.size()==2)
    //          break;
    //     }
    //   }
    //   return ans;


    // unordered_map<int,int>mpp;
    // vector<int>ans;
    // for(int i=0;i<nums.size();i++){
    //   mpp[nums[i]]++;
    // }
    //  for(auto &mp:mpp){
    //   if(mp.second>nums.size()/3)
    //   ans.push_back(mp.first);
    //  }
    //   return ans;
    // }

    int ans1=-1;int freq1=0;
    int ans2=-2;int freq2=0;
    for(int i=0;i<nums.size();i++){
        if(freq1==0&&nums[i]!=ans2){
            ans1=nums[i];
            freq1=1;
        }
        else if(freq2==0&&nums[i]!=ans1){
            ans2=nums[i];
            freq2=1;
        }
        else if(ans1==nums[i])
        freq1++;
        else if(ans2==nums[i])
        freq2++;
        else{
            freq1--;
            freq2--;
        }
    }

    vector<int>ans;
    int c1=0;int c2=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==ans1) c1++;
        if(nums[i]==ans2) c2++;
    }
    if(c1>nums.size()/3) ans.push_back(ans1);
    if(c2>nums.size()/3) ans.push_back(ans2);
    sort(ans.begin(),ans.end());
    return ans;
    }
};