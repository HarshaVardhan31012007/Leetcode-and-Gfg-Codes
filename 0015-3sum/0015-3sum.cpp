class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // int n=nums.size();
        // set<vector<int>>st;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int>temp={nums[i],nums[j],nums[k]};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans;
        // for(auto &each:st)
        // ans.push_back(each);
        // return ans;


        // int n=nums.size();
        // vector<vector<int>>ans;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     if(i>0&&nums[i]==nums[i-1]) continue;
        //     for(int j=i+1;j<n;j++){
        //         if(j>i+1&&nums[j]==nums[j-1]) continue;
        //         for(int k=j+1;k<n;k++){
        //             if(k>j+1&&nums[k]==nums[k-1]) continue;
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 ans.push_back({nums[i],nums[j],nums[k]});
        //             }
        //         }
        //     }
        // }
        // return ans;



        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int s=i+1;
            int e=n-1;
            int t=-nums[i];
            while(s<e){
                if(nums[s]+nums[e]<t){
                    s++;
                }
                else if(nums[s]+nums[e]>t){
                    e--;
                }
                else{
                    ans.push_back({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                    while(s<e&&nums[s]==nums[s-1]) s++;
                }
            }
        }
        return ans;
    }
};