class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        // long long ans=0;
        // int n=damage.size();
        // for(int i=0;i<n;i++){
        //     int temp=hp;
        //     long long score=0;
        //     for(int j=i;j<n;j++){
        //         temp-=damage[j];
        //         if(temp<=0) break;
        //         if(temp>=requirement[j])
        //             score++;
        //     }
        //     ans+=score;
        // }
        // return ans;

        int n=damage.size();
        vector<long long>prefix(n,0);
        prefix[0]=damage[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+damage[i];
        }
        long long ans=0;
        for(long long j=0;j<n;j++){
            long long p=hp-prefix[j]-requirement[j];
            if(p>=0){
            ans+=j+1;
            continue;
            }
            long long idx=lower_bound(prefix.begin(),prefix.end(),requirement[j]-hp+prefix[j])-prefix.begin();
            if(idx<j){
                ans+=j-idx;
            }            
        }
        return ans;
    }
};