class Solution {
public:
    const int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_map<long long int,int>mpp;
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        hFences.insert(hFences.begin(),1);
        hFences.push_back(m);
        vFences.insert(vFences.begin(),1);
        vFences.push_back(n);
        for(int i=0;i<hFences.size();i++){
            int x=hFences[i];
            for(int j=i+1;j<hFences.size();j++){
                int y=hFences[j];
                if(!mpp.count(y-x)){
                   mpp[y-x]=1;
                }
            }
        }
        long long int ans=-1;
        for(int i=0;i<vFences.size();i++){
            int x=vFences[i]%mod;
            for(int j=i+1;j<vFences.size();j++){
                int y=vFences[j]%mod;
                int diff=(y-x)%mod;
                if(mpp.count(diff)){
                   long long int side=diff%mod;
                   ans=max(ans,side);
                }
            }
        }
        if(ans==-1) return ans;
        return (ans*ans)%mod;
    }
};