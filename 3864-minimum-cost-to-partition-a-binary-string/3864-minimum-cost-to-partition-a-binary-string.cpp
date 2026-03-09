class Solution {
public:
    long long solve(long long s,long long e,vector<long long>&prefix,long long &ans,int &encCost,int &flatCost){
        long long mid=s+(e-s)/2;
        // long long size=mid+1;
        // long long c1=prefix[mid]-(s>0?prefix[s-1]:0);
        // long long c2=prefix[e]-prefix[mid];
        //     if(c1>0&&c2>0){
        //     ans=min(ans,size*c1*encCost+size*c2*encCost);
        //     }
        //     else if(c1>0){
        //     ans=min(ans,size*c1*encCost+flatCost);
        //     }
        //     else if(c2>0){
        //     ans=min(ans,size*c2*encCost+flatCost);
        //     }
        //     else{
        //         ans=min(ans,flatCost+flatCost);
        //     }
        // if(size&1) return;
        long long c=prefix[e]-(s>0?prefix[s-1]:0);
        long long len=e-s+1;
        long long curr;
        if(c>0)
        curr=c*len*encCost;
        else
        curr=flatCost;
        if(len&1) return curr;
        long long l=solve(s,mid,prefix,ans,encCost,flatCost);
        long long r=solve(mid+1,e,prefix,ans,encCost,flatCost);
        return min(l+r,curr);
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n=s.length();
        long long ans=LLONG_MAX;
        vector<long long>prefix(n,0);
        long long c=0;
        for(int i=0;i<n;i++){
            c+=(s[i]=='1'?1:0);
            prefix[i]=c;
        }
        if(c>0){
            ans=min(ans,c*n*encCost);
        }
        else{
            ans=min(ans,1LL*flatCost);
        }
        if(n&1) return ans;
        long long temp=solve(0,n-1,prefix,ans,encCost,flatCost);
        return min(temp,ans);
    }
};