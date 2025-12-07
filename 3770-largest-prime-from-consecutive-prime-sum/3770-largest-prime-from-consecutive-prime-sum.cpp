class Solution {
public:
    int largestPrime(int n) {
        vector<bool>primes(n+1,1);
        for(int i=2;i<=sqrt(n);i==2?i=i+1:i=i+2){
            if(primes[i]==0) continue;
            int j=i;
            int p=2;
            while(j*p<=n){
                primes[j*p]=0;
                p++;
            }
        }
        long long sum=0;
        vector<long long>v;
        long long ans=0;
        for(int i=2;i<=n;i==2?i=i+1:i=i+2){
            if(primes[i]==0) continue;
            sum+=i;
            v.push_back(sum);
            if(binary_search(v.begin(),v.end(),i))  ans=i;
        }
        return ans;
    }
};