class Solution {
public:
    // int find(int n){
    //     int num=0;
    //     while(n){
    //         int digit=n%2;
    //         num=num*2+digit;
    //         n=n/2;
    //     }
    //     return num;
    // }
    // vector<int> sortByReflection(vector<int>& nums) {
    //      vector<pair<int,int>>v;
    //      for(int i=0;i<nums.size();i++){
    //          int curr=find(nums[i]);
    //          v.push_back({curr,nums[i]});
    //      }
    //     sort(v.begin(),v.end());
    //     vector<int>ans;
    //     for(auto &each:v)
    //         ans.push_back(each.second);
    //     return ans;
    // }

    
    int Reflect(int x){
        int num=0;
        while(x){
            num=num*2+(x%2);
            x=x/2;
        }
        return num;
    }
    vector<int> sortByReflection(vector<int>& nums) {
         sort(nums.begin(),nums.end(),[&](int x,int y){
              return make_pair(Reflect(x),x)<make_pair(Reflect(y),y);
         });
         return nums;
    }
};