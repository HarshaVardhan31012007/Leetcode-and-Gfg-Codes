class Solution {
public:
    // long long minimumCost(vector<int>& nums, int k, int dist) {
    //     int i=1;int j=i+dist;int n=nums.size();
    //     int sum=0;
    //     int ans=INT_MAX;
    //     set<pair<int,int>>st;
    //     for(int p=i;p<=j;p++){
    //         if(st.size()<k-1){
    //             st.insert({nums[p],p});
    //             sum+=nums[p];
    //         }
    //         else{
    //             st.insert({nums[p],p});
    //             int diff=st.find({nums[p],p})-st.begin();
    //             if(diff<=(k-2)){
    //                 sum+=nums[p];
    //                 it=st.begin()+k-1;
    //                 sum-=(*it);
    //             }
    //         }
    //     }
    //     ans=min(ans,nums[0]+sum);
    //     int diff=st.find({nums[i],i})-st.begin();
    //     if(diff<=k-2){
    //         sum-=nums[i];
    //     }
    //     st.erase({nums[i],i})
    //     i++;j++;
    //     while(j<n){
    //         if(st.size()<k-1){
    //            st.insert({nums[j],j});
    //            sum+=nums[j];
    //         }
    //         else{
    //             st.insert({nums[j],j});
    //             int diff=st.find({nums[j],j})-st.begin();
    //             if(diff<=(k-2)){
    //                 sum+=nums[p];
    //                 it=st.begin()+k-1;
    //                 sum-=(*it);
    //             }   
    //         }
    //         ans=min(ans,nums[0]+sum);
    //         int diff=st.find({nums[i],i})-st.begin();
    //         if(diff<=k-2){
    //             sum-=nums[i];
    //         }
    //         st.erase({nums[i],i})
    //         i++;
    //         j++;
    //     }
    //     return ans;
    // }



     long long minimumCost(vector<int>& nums, int k, int dist) {
        int i=1;int j=i+dist;int n=nums.size();
        long long int sum=0;
        long long int ans=LLONG_MAX;
        set<pair<long long int,int>>st;
        set<pair<long long int,int>>st1;
        for(int p=i;p<=j;p++){
            if(st.size()<k-1){
                st.insert({nums[p],p});
                sum+=nums[p];
            }
            else{
                auto it=st.end();
                it--;
                if(it->first<=nums[p]){
                    st1.insert({nums[p],p});
                }
                else{
                    st.insert({nums[p],p});
                    sum+=nums[p];
                    it=st.end();
                    it--;
                    sum-=it->first;
                    st1.insert({it->first,it->second});
                    st.erase(it);
                }
            }
        }
        ans=min(ans,nums[0]+sum);
        cout<<sum<<endl;
        if(st.count({nums[i],i})){
            st.erase({nums[i],i});
            sum-=nums[i];
            if(!st1.empty()){
                auto it=st1.begin();
                st.insert({it->first,it->second});
                sum+=it->first;
                st1.erase(it);
            }
        }
        else{
            st1.erase({nums[i],i});
        }
        i++;j++;
        while(j<n){
            if(st.size()<k-1){
               st.insert({nums[j],j});
               sum+=nums[j];
            }
            else{
                auto it=st.end();
                it--;
                if(it->first<=nums[j]){
                    st1.insert({nums[j],j});
                }
                else{
                    st.insert({nums[j],j});
                    sum+=nums[j];
                    it=st.end();
                    it--;
                    sum-=it->first;
                    st1.insert({it->first,it->second});
                    st.erase(it);
                }
            }
            ans=min(ans,1LL*nums[0]+sum);
            if(st.count({nums[i],i})){
                st.erase({nums[i],i});
                sum-=nums[i];
                if(!st1.empty()){
                    auto it=st1.begin();
                    st.insert({it->first,it->second});
                    sum+=it->first;
                    st1.erase(it);
                }
            }
            else{
                st1.erase({nums[i],i});
            }
            i++;
            j++;
        }
        return ans;
    }
};