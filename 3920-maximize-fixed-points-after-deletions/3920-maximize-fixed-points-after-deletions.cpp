class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
       vector<pair<int,int>>v;
       for(int i=0;i<nums.size();i++){
          v.push_back({i-nums[i],nums[i]});
       }
       sort(v.begin(),v.end());
       vector<int>ans;
       for(auto &each:v){
        if(each.first<0) continue;
          int curr=each.second;
          if(ans.empty()||curr>ans.back()){
            ans.push_back(curr);
          }
          else{
            auto idx=lower_bound(ans.begin(),ans.end(),curr)-ans.begin();
            ans[idx]=curr;
          }
       }
       return ans.size();
    }
};