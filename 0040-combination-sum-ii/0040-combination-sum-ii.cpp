// class Solution {
// public:
//     void solve(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&temp,int i){
//          if(target==0){
//               // if(ans.find(temp)==ans.end())
//             //   vector<int>a(temp.begin(),temp.end());
//             //   sort(a.begin(),a.end());
//                ans.push_back(temp);
//                return;
//          } 
//          if(i==candidates.size()||target<0) return; 
//          temp.push_back(candidates[i]);
//          solve(candidates,target-candidates[i],ans,temp,i+1);
//          temp.pop_back();  
//          while(i+1<candidates.size()&&candidates[i]==candidates[i+1])
//          i++;
//          solve(candidates,target,ans,temp,i+1);
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<vector<int>>ans;
//         sort(candidates.begin(),candidates.end());
//         vector<int>temp;
//         solve(candidates,target,ans,temp,0);
//         return ans;
//     }
// };



class Solution {
public:
    void solve(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&temp,int i){
         if(target==0){
               ans.push_back(temp);
               return;
         } 
         if(i==candidates.size()||target<0) return;
         for(int index=i;index<candidates.size();index++){
            if(index>i&&candidates[index]==candidates[index-1])
            continue;
            temp.push_back(candidates[index]);
            solve(candidates,target-candidates[index],ans,temp,index+1);
            temp.pop_back();
         }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        solve(candidates,target,ans,temp,0);
        return ans;
    }
};