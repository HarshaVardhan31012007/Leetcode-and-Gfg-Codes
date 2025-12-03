class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        // vector<pair<int,int>>v;
        // int n=nums1.size();
        // for(int i=0;i<n;i++){
        //     v.push_back({nums1[i],i});
        // }
        // sort(v.begin(),v.end());
        // vector<long long>ans(n,0);
        // priority_queue<int,vector<int>,greater<>>pq;
        // long long sum=0;
        // for(int i=0;i<v.size();i++){
        //     ans[v[i].second]=sum;
        //     if(i+1<n&&v[i+1].first>v[i].first){
        //         ans[v[i].second]=sum;
        //         pq.push(nums2[v[i].second]);
        //         sum+=nums2[v[i].second];
        //         if(pq.size()>k){
        //             sum-=pq.top();
        //             pq.pop();
        //         }
        //     }
        //     else {
        //         int temp=sum;
        //         while(i+1<n&&v[i+1].first==v[i].first){
        //             ans[v[i].second]=temp;
        //             pq.push(nums2[v[i].second]);
        //             sum+=nums2[v[i].second];
        //             if(pq.size()>k){
        //                 sum-=pq.top();
        //                 pq.pop();
        //             }
        //             i++;
        //             if(i<n){
        //                 ans[v[i].second]=temp;
        //                 pq.push(nums2[v[i].second]);
        //                 sum+=nums2[v[i].second];
        //                 if(pq.size()>k){
        //                     sum-=pq.top();
        //                     pq.pop();
        //                 }
        //             }
        //         } 
        //     }
        // }
        // return ans;




        vector<pair<int,int>>v;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            v.push_back({nums1[i],i});
        }
        sort(v.begin(),v.end());
        vector<long long>ans(n,0);
        priority_queue<int,vector<int>,greater<>>pq;
        long long sum=0;
        for(int i=0;i<v.size();i++){
            if(i==0||v[i].first>v[i-1].first)
            ans[v[i].second]=sum;
            else
            ans[v[i].second]=ans[v[i-1].second];
            pq.push(nums2[v[i].second]);
            sum+=nums2[v[i].second];
            if(pq.size()>k){
            sum-=pq.top();
            pq.pop();
            }
        }
        return ans;
    }
};