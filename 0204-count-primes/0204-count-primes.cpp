class Solution {
public:
    // bool isprime(int n){
    //     if(n<=1)
    //     return false;
    //     for(int i=2;i<n;i++){//i<sqrt(n)
    //         if(n%i==0)
    //         return false;
    //     }
    //     return true;
   // }
    int countPrimes(int n) {
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(isprime(i))
        //     count++;
        // }
        // return count;

        if(n==0) return 0;
        vector<bool>temp(n,true);
        temp[0]=temp[1]=false;
        int ans=0;
        for(int i=0;i<n;i++){
            if(temp[i]){
            ans++;
            int j=2*i;
            while(j<n){
                temp[j]=false;
                j=j+i;
            }

            }

        }
        return ans;

        // if(n==0) return 0;
        // vector<bool>temp(n,true);
        // temp[0]=temp[1]=false;
        // int ans=0;
        // for(int i=2;i<n;i++){
        //    for(int j=2*i;j<n;j+=i){
        //         temp[j]=false;
        //    }
        //    if(temp[i])
        //    ans++;
        // }
        
        // return ans;
    }
};