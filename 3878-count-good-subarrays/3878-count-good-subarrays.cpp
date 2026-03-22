class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        // long long count=0;
        // long long n=nums.size();
        // unordered_map<int,int>mpp;
        // for(auto &each:nums)
        // mpp[each]++;
        // for(int i=0;i<n;i++){
        //     int mask=nums[i];
        //     int j=i;
        //     while(j>=0&&((nums[j]&mask)==nums[j])){
        //         j--;
        //         if(j>=0&&nums[j]==nums[i]) break;
        //     }
        //     count+=(i-j);
        //     int left=(i-j-1);
        //     j=i+1;
        //     while(j<n&&((nums[j]&mask)==nums[j])){
        //         j++;
        //     }
        //     count+=(j-i-1);
        //     int right=(j-i-1);
        //     if(left>=1&&right>=1){
        //         count+=left*right;
        //     }
        // }
        // return count;



        // long long count=0;
        // long long n=nums.size();
        // unordered_map<int,int>mpp;
        // for(auto &each:nums)
        // mpp[each]++;
        // for(int i=0;i<n;i++){
        //     int mask=nums[i];
        //     int j=i;
        //     while(j>=0&&((nums[j]&mask)==nums[j])){
        //         j--;
        //         if(j>=0&&nums[j]==nums[i]) break;
        //     }
        //     count+=(i-j);
        //     int left=(i-j-1);
        //     j=i+1;
        //     while(j<n&&((nums[j]&mask)==nums[j])){
        //         j++;
        //     }
        //     count+=(j-i-1);
        //     int right=(j-i-1);
        //     if(left>=1&&right>=1){
        //         count+=left*right;
        //     }
        // }
        // return count;


        // long long n=nums.size();
        // vector<int>suffix(n,n);
        // vector<int>nextClosestBit(32,n);
        // unordered_map<int,int>mpp;
        // for(int i=n-1;i>=0;i--){
        //     int mini=n;
        //     for(int j=31;j>=0;j--){
        //         if((nums[i]>>j)&1) nextClosestBit[j]=i;
        //         else mini=min(mini,nextClosestBit[j]);
        //     }
        //     suffix[i]=mini;
        //     if(mpp.count(nums[i])) suffix[i]=min(suffix[i],mpp[nums[i]]);
        //     mpp[nums[i]]=i;
        // }
        // vector<int>prevClosestBit(32,-1);
        // long long int ans=0;
        // for(int i=0;i<n;i++){
        //     int maxi=-1;
        //     for(int j=31;j>=0;j--){
        //         if((nums[i]>>j)&1) prevClosestBit[j]=i;
        //         else maxi=max(maxi,prevClosestBit[j]);
        //     }
        //     ans+=(i-maxi)*(suffix[i]-i);
        // }
        // return ans;



        // long long n=nums.size();
        // vector<int>prefix(n,-1);
        // stack<int>st;
        // for(int i=n-1;i>=0;i--){
        //    while(!st.empty()&&((nums[st.top()]|nums[i])>nums[st.top()]||nums[i]==nums[st.top()])){
        //       prefix[st.top()]=i;
        //       st.pop();
        //    }
        //    st.push(i);
        // }
        // vector<int>suffix(n,n);
        // stack<int>st1;
        // for(int i=0;i<n;i++){
        //    while(!st1.empty()&&(nums[st1.top()]|nums[i])>nums[st1.top()]){
        //       suffix[st1.top()]=i;
        //       st1.pop();
        //    }
        //    st1.push(i);
        // }
        // long long int ans=0;
        // for(int i=0;i<n;i++)
        // ans+=(i-prefix[i])*(suffix[i]-i);
        // return ans;



        long long n=nums.size();
        vector<int>suffix(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
           while(!st.empty()&&(nums[st.top()]|nums[i])==nums[i]){
              st.pop();
           }
           if(!st.empty())
           suffix[i]=st.top();
           st.push(i);
        }
        vector<int>prefix(n,-1);
        stack<int>st1;
        for(int i=0;i<n;i++){
           while(!st1.empty()&&((nums[st1.top()]|nums[i])==nums[i])&&nums[st1.top()]!=nums[i]){
             st1.pop();
           }
           if(!st1.empty())
           prefix[i]=st1.top();
           st1.push(i);
        }
        long long int ans=0;
        for(int i=0;i<n;i++)
        ans+=(i-prefix[i])*(suffix[i]-i);
        return ans;
    }
};