class Solution {
public:
    // long long maximumScore(vector<int>& nums, string s) {
    //     priority_queue<int>pq;
    //     long long ans=0;
    //     for(int j=0;j<nums.size();j++){
    //         pq.push(nums[j]);
    //         if(s[j]=='1'){
    //             ans+=pq.top();
    //             pq.pop();
    //         }
    //     }
    //     return ans;
    // }



    // long long maximumScore(vector<int>& nums, string s) {
    //     priority_queue<int>pq;
    //     long long ans=0;
    //     for(int j=0;j<nums.size();j++){
    //         pq.push(nums[j]);
    //         if(s[j]=='1'){
    //             ans+=pq.top();
    //             pq.pop();
    //         }
    //     }
    //     return ans;
    // }




     long long maximumScore(vector<int>& nums, string s) {
        // priority_queue<int>pq;
        // long long ans=0;
        // for(int j=0;j<nums.size();j++){
        //     pq.push(nums[j]);
        //     if(s[j]=='1'){
        //         ans+=pq.top();
        //         pq.pop();
        //     }
        // }
        // return ans;


        set<int>st;
        vector<pair<int,int>>v;
        for(int j=0;j<nums.size();j++){
            if(s[j]=='1'){
                st.insert(j);
            }
            v.push_back({nums[j],j});
        }
        sort(v.rbegin(),v.rend());
        long long ans=0;
        for(int i=0;i<v.size();i++){
            if(st.empty()) break;
            auto it=st.lower_bound(v[i].second);
            if(it==st.end()) continue;
            ans+=v[i].first;
            st.erase(it);
        }
        return ans;
    }
};