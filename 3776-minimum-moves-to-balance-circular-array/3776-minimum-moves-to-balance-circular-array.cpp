class Solution {
public:
    // long long solve(vector<int>&balance,int i){
    //     int k1=i-1;
    //     int k2=i+1;
    //     int n=balance.size();
    //     long long ans=0;
    //     while(1){
    //         int idx1=(k1+n)%n;
    //         int idx2=(k2)%n;
    //         if(idx1>=0&&idx1<n&&balance[idx1]>0){
    //             int need=abs(balance[i]);
    //             long long curr=1LL*(i-k1)*(min(need,balance[idx1]));
    //             balance[i]+=min(need,balance[idx1]);
    //             balance[idx1]-=min(need,balance[idx1]);
    //             ans+=curr;
    //         }
    //         if(balance[i]==0) break;
    //         if(idx2>=0&&idx2<n&&balance[idx2]>0){
    //             int need=abs(balance[i]);
    //             long long curr=1LL*(k2-i)*(min(need,balance[idx2]));
    //             balance[i]+=min(need,balance[idx2]);
    //             balance[idx2]-=min(need,balance[idx2]);
    //             ans+=curr;
    //         }
    //         if(balance[i]==0) break;
    //         k1--;
    //         k2++;
    //     }
    //     return ans;
    // }
    // long long minMoves(vector<int>& balance) {
    //     long long sum=accumulate(balance.begin(),balance.end(),0LL);
    //     if(sum<0) return -1;
    //     long long ans=0;
    //     for(int i=0;i<balance.size();i++){
    //         if(balance[i]<0)
    //         ans+=solve(balance,i);
    //     }
    //     return ans;
    // }




    typedef long long ll;
    long long minMoves(vector<int>& balance) {
        ll sum=0;
        ll idx=-1;
        for(int i=0;i<balance.size();i++){
            sum+=balance[i];
            if(balance[i]<0)
            idx=i;
        }
        if(sum<0) return -1;//if we transfer all value then also still sum is negative that means it is not possible to make all elements non negative 
        if(idx==-1) return 0;//no negative value
        ll moves=0;
        ll dist=1;
        int n=balance.size();
        while(balance[idx]<0){
            int l=(idx-dist+n)%n;
            int r=(idx+dist)%n;
            ll available=balance[l]+balance[r];
            if(l==r)
            available-=balance[l];
            ll need=-balance[idx];
            ll taken=min(need,available);
            moves+=taken*dist;
            balance[idx]+=taken;
            dist++;
        }
        return moves;
    }
};