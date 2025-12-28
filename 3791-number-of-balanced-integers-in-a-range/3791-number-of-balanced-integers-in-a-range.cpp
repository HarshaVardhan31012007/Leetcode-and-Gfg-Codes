// class Solution {
// public:
//     long long count(long long n){
//         long long ans=0;
//         while(n){
//             ans++;
//             n=n/10;
//         }
//         return ans;
//     }
//     map<vector<long long>,long long>mpp;
//     long long solve(long long digits,long long sum,long long sign,long long n,long long low,long high){
//         if(digits==0){
//             if(sum==0&&n>=low&&n<=high){
//                 return 1LL;
//             } 
//             return 0LL;
//         }
//         if(mpp.count({digits,sum,sign,n})) return mpp[{digits,sum,sign,n}];
//         long long ans=0;
//         for(long long i=0;i<10;i++){
//             if(n==0&&i==0) continue;
//             ans+=solve(digits-1LL,sum+i*sign,sign*-1LL,n*10LL+i,low,high);
//         }
//         return mpp[{digits,sum,sign,n}]=ans;
//     }
//     long long countBalanced(long long low, long long high) {
//        if(high<10) return  0;
//        long long minDigit=max(low,10LL);
//        long long l=count(minDigit);
//        long long r=count(high);
//        long long ans=0;
//        for(long long j=l;j<=r;j++){
//             ans+=solve(j,0,1,0,minDigit,high);
//        }
//        return ans;
//     }
// };




class Solution {
public:
    long long solve1(string &s,int i,int diff,bool lz,bool tight,map<tuple<int,int,bool,bool>,long long>&dp){
        if(i==s.length()){
            return diff==0&&!lz;
        }
        if(dp.count({i,diff,lz,tight})) return dp[{i,diff,lz,tight}];
        int lim=(tight==1?s[i]-'0':9);
        long long res=0;
        for(int j=0;j<=lim;j++){
            int ndiff=diff;
            bool nlz=!lz&&j==0;
            if(!nlz){
               if(i%2==0)
               ndiff+=j;
               else
               ndiff-=j;
            }
            res+=solve1(s,i+1,ndiff,lz&&j==0,tight&&j==lim,dp);
        }
        return dp[{i,diff,lz,tight}]=res;
    }
    long long solve(string &s){
        int n=s.length();
        map<tuple<int,int,bool,bool>,long long>dp;
        return solve1(s,0,0,1,1,dp);
    }
    long long countBalanced(long long low, long long high) {
       string l=to_string(low-1);
       string r=to_string(high);
       return solve(r)-solve(l);
    }
};