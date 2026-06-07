class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // int n=nums.size();
        // int i=0;
        // int j=0;
        // set<pair<int,int>>st;
        // int ans=1;
        // while(j<n){
        //     st.insert({nums[j],j});
        //     auto it=st.end();it--;
        //     int maxi=it->first;
        //     int mini=st.begin()->first;
        //     if((maxi-mini)>limit){
        //         st.erase({nums[i],i});
        //         i++;
        //         it=st.end();it--;
        //         maxi=it->first;
        //         mini=st.begin()->first;
        //     }
        //     if((maxi-mini)<=limit)
        //     ans=max(ans,(j-i+1));
        //     j++;
        // }
        // return ans;



        int n=nums.size();
        int i=0;
        int j=0;
        deque<int>dq1;
        deque<int>dq2;
        int ans=1;
        while(j<n){
            while(!dq1.empty()&&nums[dq1.back()]<=nums[j]){
                dq1.pop_back();
            }
            dq1.push_back(j);
            while(!dq2.empty()&&nums[dq2.back()]>=nums[j]){
                dq2.pop_back();
            }
            dq2.push_back(j);
            int mini=nums[dq2.front()];
            int maxi=nums[dq1.front()];
            if((maxi-mini)>limit){
                if(dq1.front()<=i) dq1.pop_front();
                if(dq2.front()<=i) dq2.pop_front();
                i++;
                mini=nums[dq2.front()];
                maxi=nums[dq1.front()];
            }
            if((maxi-mini)<=limit)
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};