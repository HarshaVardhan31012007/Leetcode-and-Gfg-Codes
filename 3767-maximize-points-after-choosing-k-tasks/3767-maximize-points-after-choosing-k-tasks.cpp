class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        // unordered_map<int,bool>mpp;
        // long long ans=0;
        // int n=technique1.size();
        // for(int i=0;i<n;i++){
        //     int maxi=max(technique1[i],technique2[i]);
        //     if(maxi==technique2[i])
        //         mpp[i]=1;
        //     ans+=maxi;
        // }
        // if(n-mpp.size()>=k) return ans;
        // int count=k-(n-mpp.size());
        // vector<pair<int,int>>diff;
        // for(int i=0;i<n;i++){
        //     diff.push_back({technique2[i]-technique1[i],i});
        // }
        // sort(diff.begin(),diff.end());
        // for(auto &each:diff){
        //     if(mpp.count(each.second)){
        //         if(count>0){
        //             ans-=each.first;
        //             count--;
        //         }
        //         else
        //             break;
        //     }
        // }
        // return ans;



       
        // long long ans=0;
        // int n=technique1.size();
        // vector<int>diff;
        // int size=0;
        // for(int i=0;i<n;i++){
        //     int maxi=max(technique1[i],technique2[i]);
        //     if(maxi==technique2[i]){
        //         size++;
        //         diff.push_back(technique2[i]-technique1[i]);
        //     }
        //     ans+=maxi;
        // }
        // if(n-size>=k) return ans;
        // int count=k-(n-size);
        // sort(diff.begin(),diff.end());
        // for(auto &each:diff){
        //     if(count>0){
        //         ans-=each;
        //         count--;
        //     }
        //     else
        //     break;
        // }
        // return ans;



        // long long ans=0;
        // int n=technique1.size();
        // priority_queue<int,vector<int>,greater<>>pq;
        // int size=0;
        // for(int i=0;i<n;i++){
        //     int maxi=max(technique1[i],technique2[i]);
        //     if(maxi==technique2[i]){
        //         size++;
        //         ans+=maxi;
        //         pq.push(technique2[i]-technique1[i]);
        //         if(size>n-k){
        //             ans-=pq.top();
        //             pq.pop();
        //         }
        //     }
        //     else
        //     ans+=maxi;
        // }
        // return ans;




        long long ans=0;
        int n=t1.size();
        vector<pair<int,int>>diff;
        for(int i=0;i<n;i++){
            diff.push_back({t1[i]-t2[i],i});
        }
        sort(diff.begin(),diff.end(),[&](pair<int,int>p,pair<int,int>q){
            return p.first>q.first;
        });
        for(int i=0;i<k;i++){
            ans+=t1[diff[i].second];
        }
        for(int i=k;i<n;i++){
            if(diff[i].first>0){
                ans+=t1[diff[i].second];
            }
            else{
                ans+=t2[diff[i].second];
            }
        }
        return ans;
    }
};