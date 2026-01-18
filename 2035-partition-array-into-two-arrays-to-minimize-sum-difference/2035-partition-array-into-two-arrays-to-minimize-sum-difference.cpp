class Solution {
public:
    // int solve(vector<int>&nums,int i,int sum,int n,int total,vector<vector<unordered_map<int,int>>>&dp){
    //     if(n==0){
    //        int other=total-sum;
    //        return abs(sum-other);
    //     }
    //     if(i>=nums.size()){
    //         return 1e8;
    //     }
    //     if(dp[i][n].count(sum)) return dp[i][n][sum];
    //     int inc=solve(nums,i+1,sum+nums[i],n-1,total,dp);
    //     int exc=solve(nums,i+1,sum,n,total,dp);
    //     return dp[i][n][sum]=min(inc,exc);
    // }
    // int minimumDifference(vector<int>& nums) {
    //     int t=accumulate(nums.begin(),nums.end(),0);
    //     vector<vector<unordered_map<int,int>>>dp(nums.size()+1,vector<unordered_map<int,int>>(nums.size()/2+1));
    //     return solve(nums,0,0,nums.size()/2,t,dp);
    // }

//  int minimumDifference(vector<int>& arr) {
//         int t=accumulate(arr.begin(),arr.end(),0);
//     int n=arr.size();
//         int mid=n/2;
//         vector<int>left(arr.begin(),arr.begin()+mid);
//         vector<int>right(arr.begin()+mid,arr.end());
//         int m=left.size();n=right.size();
//         vector<int>leftS,rightS;
//         for(int mask=0;mask<(1<<m);mask++){
//             int temp=mask;
//             int i=0;int sum=0;
//             while(temp){
//                 if(temp&1){
//                     sum+=left[i];
//                 }
//                 temp=temp>>1;i++;
//             }
//             leftS.push_back(sum);
//         }
//         for(int mask=0;mask<(1<<n);mask++){
//             int temp=mask;
//             int i=0;int sum=0;
//             while(temp){
//                 if(temp&1){
//                     sum+=right[i];
//                 }
//                 temp=temp>>1;i++;
//             }
//             rightS.push_back(sum);
//         }
//         sort(rightS.begin(),rightS.end());
//         int ans=0;
//         for(auto &each:leftS){
//             int need=k-each;
//             int count=upper_bound(rightS.begin(),rightS.end(),need)-lower_bound(rightS.begin(),rightS.end(),need);
//             ans+=count;
//         }
//         return ans;
//}




    int minimumDifference(vector<int>& nums) {
        // int n = nums.size();
        // int half = n / 2;

        // vector<int> A(nums.begin(), nums.begin() + half);
        // vector<int> B(nums.begin() + half, nums.end());

        // int sum = accumulate(nums.begin(), nums.end(), 0);

        // vector<vector<int>> left(half + 1), right(half + 1);

        // // Generate subset sums for A
        // for (int mask = 0; mask < (1 << half); mask++) {
        //     int cnt = 0, s = 0;
        //     for (int i = 0; i < half; i++) {
        //         if (mask & (1 << i)) {
        //             cnt++;
        //             s += A[i];
        //         }
        //     }
        //     left[cnt].push_back(s);
        // }

        // // Generate subset sums for B
        // int n2 = n - half;
        // for (int mask = 0; mask < (1 << n2); mask++) {
        //     int cnt = 0, s = 0;
        //     for (int i = 0; i < n2; i++) {
        //         if (mask & (1 << i)) {
        //             cnt++;
        //             s += B[i];
        //         }
        //     }
        //     right[cnt].push_back(s);
        // }

        // // Sort right subsets
        // for (int i = 0; i <= half; i++) {
        //     sort(right[i].begin(), right[i].end());
        // }

        // int ans = INT_MAX;

        // // Combine
        // for (int k = 0; k <= half; k++) {
        //     for (int s1 : left[k]) {
        //         int need = half - k;
        //         auto &vec = right[need];
        //         int target = sum / 2 - s1;

        //         auto it = lower_bound(vec.begin(), vec.end(), target);

        //         if (it != vec.end()) {
        //             ans = min(ans, abs(sum - 2 * (s1 + *it)));
        //         }
        //         if (it != vec.begin()) {
        //             --it;
        //             ans = min(ans, abs(sum - 2 * (s1 + *it)));
        //         }
        //     }
        // }
        // return ans;


        int n=nums.size();
        int mid=n/2;
        vector<int>left(nums.begin(),nums.begin()+mid);
        vector<int>right(nums.begin()+mid,nums.end());
        int t=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>leftv(mid+1);vector<vector<int>>rightv(mid+1);
        for(int mask=0;mask<(1<<mid);mask++){
            int s=0;int c=0;
            for(int i=0;i<mid;i++){
                if(mask&(1<<i)){
                    s+=left[i];
                    c++;
                }
            }
            leftv[c].push_back(s);
        }
        for(int mask=0;mask<(1<<mid);mask++){
            int s=0;int c=0;
            for(int i=0;i<mid;i++){
                if(mask&(1<<i)){
                    s+=right[i];
                    c++;
                }
            }
            rightv[c].push_back(s);
        }
        for(auto &each:rightv){
            sort(each.begin(),each.end());
        }
        int ans=INT_MAX;
        for(int i=0;i<mid;i++){
            for(auto &each:leftv[i+1]){
                int need=mid-i-1;
                int value=t/2-each;
                auto it=lower_bound(rightv[need].begin(),rightv[need].end(),value);
                if(it!=rightv[need].end()){
                    ans=min(ans,abs(t-2*(each+*it)));
                }
                else if(it!=rightv[need].begin()){
                   it--;
                   ans=min(ans,abs(t-2*(each+*it)));
                }
            }
        }
        return ans;
    }
};