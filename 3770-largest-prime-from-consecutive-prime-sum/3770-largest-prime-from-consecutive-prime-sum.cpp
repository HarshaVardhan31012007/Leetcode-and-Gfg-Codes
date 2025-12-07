class Solution {
public:
    // int largestPrime(int n) {
    //     vector<bool>primes(n+1,1);
    //     for(int i=2;i<=sqrt(n);i==2?i=i+1:i=i+2){
    //         if(primes[i]==0) continue;
    //         // int j=i;
    //         // int p=2;
    //         int j=i;
    //         int p=i;//2*3 and 3*3 to avoid repetitive things
    //         while(j*p<=n){
    //             primes[j*p]=0;
    //             p++;
    //         }
    //     }
    //     long long sum=0;
    //     vector<long long>v;
    //     long long ans=0;
    //     for(int i=2;i<=n;i==2?i=i+1:i=i+2){
    //         if(primes[i]==0) continue;
    //         sum+=i;
    //         v.push_back(sum);
    //         if(binary_search(v.begin(),v.end(),i))  ans=i;
    //     }
    //     return ans;
    // }



     int largestPrime(int n) {
        vector<bool>primes(n+1,1);
        for(int i=2;i<=sqrt(n);i==2?i=i+1:i=i+2){
            if(primes[i]==0) continue;
            // int j=i;
            // int p=2;
            // int j=i;
            // int p=i;//2*3 and 3*3 to avoid repetitive things
            // while(j*p<=n){
            //     primes[j*p]=0;
            //     p+=
            // }

            int j=i*i;//2*3 and 3*3 to avoid repetitive things
            while(j<=n){
                primes[j]=0;
                j+=i;
            }
        }
        // long long sum=0;
        // unordered_map<long long,bool>mpp;//TLE for n=199 as sum can be more and more large to store//more time to store//vector is better than map for accessing
        // long long ans=0;
        // for(int i=2;i<=n;i==2?i=i+1:i=i+2){
        //     if(primes[i]==0) continue;
        //     sum+=i;
        //     mpp[sum]=1;
        //     if(mpp.count(i))  ans=i;
        // }
        vector<long long>v;
        long long ans=0;
        for(int i=2;i<=n;i++){
            if(primes[i])
            v.push_back(i);
        }
        long long sum=0;
        for(auto &each:v){
            sum+=each;
            if(sum>n) break;
            if(primes[sum])
            ans=sum;
        }
        return ans;
    }

};