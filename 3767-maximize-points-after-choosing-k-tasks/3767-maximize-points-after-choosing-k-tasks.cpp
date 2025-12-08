class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
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



       
        long long ans=0;
        int n=technique1.size();
        vector<bool>visited(n,0);
        int size=0;
        for(int i=0;i<n;i++){
            int maxi=max(technique1[i],technique2[i]);
            if(maxi==technique2[i]){
                visited[i]=1;
                size++;
            }
            ans+=maxi;
        }
        if(n-size>=k) return ans;
        int count=k-(n-size);
        vector<pair<int,int>>diff;
        for(int i=0;i<n;i++){
            diff.push_back({technique2[i]-technique1[i],i});
        }
        sort(diff.begin(),diff.end());
        for(auto &each:diff){
            if(visited[each.second]){
                if(count>0){
                    ans-=each.first;
                    count--;
                }
                else
                    break;
            }
        }
        return ans;
    }
};