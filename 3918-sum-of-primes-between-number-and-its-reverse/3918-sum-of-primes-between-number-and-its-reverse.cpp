// class Solution {
// public:
//     vector<bool>isprime;
//     int sumOfPrimesInRange(int n) {
//         isprime.assign(1001,1);
//         isprime[0]=0;isprime[1]=0;
//         for(int i=2;i*i<=1000;i++){
//             for(int j=i*i;j<=1000;j+=i){
//                 isprime[j]=0;
//             }
//         }
//         string s=to_string(n);
//         reverse(s.begin(),s.end());
//         int m=stoi(s);
//         int l=min(m,n);
//         int r=max(m,n);
//         int sum=0;
//         for(int i=l;i<=r;i++){
//             if(isprime[i]){
//                 sum+=i;
//             }
//         }
//         return sum;
//     }
// };



// class Solution {
// public:
//     vector<bool>isprime;
//     int findrev(int n){
//         int k=0;
//         while(n){
//             k=k*10+(n%10);
//             n=n/10;
//         } 
//         return k;
//     }
//     int sumOfPrimesInRange(int n) {
//         isprime.assign(1001,1);
//         isprime[0]=0;isprime[1]=0;
//         for(int i=2;i*i<=1000;i++){
//             for(int j=i*i;j<=1000;j+=i){
//                 isprime[j]=0;
//             }
//         }
//         int m=findrev(n);
//         int l=min(m,n);
//         int r=max(m,n);
//         int sum=0;
//         for(int i=l;i<=r;i++){
//             if(isprime[i]){
//                 sum+=i;
//             }
//         }
//         return sum;
//     }
// };




// class Solution {
// public:
//     vector<bool>isprime;
//     int findrev(int n){
//         int k=0;
//         while(n){
//             k=k*10+(n%10);
//             n=n/10;
//         } 
//         return k;
//     }
//     int sumOfPrimesInRange(int n) {
//         int m=findrev(n);
//         int l=min(m,n);
//         int r=max(m,n);
//         int k=sqrt(r);
//         vector<bool>isprime(k+1,1);
//         isprime[0]=isprime[1]=0;
//         for(int i=2;i*i<=k;i++){
//             for(int j=i*i;j<=k;j+=i){
//                isprime[j]=0;
//             }
//         }
//         vector<bool>isprime1(r-l+1,1);
//         for(int i=2;i*i<=r;i++){
//             if(isprime[i]){
//                 int one=((l/i)*i);
//                 if(one<l) one+=i;
//                 int first=max(i*i,one);
//                 for(int j=first;j<=r;j+=i){
//                    isprime1[j-l]=0;
//                 }
//             }
//         }
//         if(l==1){
//             isprime1[0]=0;
//         }
//         int sum=0;
//         for(int i=l;i<=r;i++){
//             if(isprime1[i-l]){
//                 sum+=i;
//             }
//         }
//         return sum;
//     }
// };



class Solution {
public:
    vector<bool>isprime;
    int findrev(int n){
        int k=0;
        while(n){
            k=k*10+(n%10);
            n=n/10;
        } 
        return k;
    }
    bool isPrime(int n){
        if(n<2) return false;
        if(n==2||n==3) return true;
        if(n%2==0||n%3==0) return false;
        for(int x=4;x*x<=n;x++){
            if(n%x==0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int m=findrev(n);
        int sum=0;
        for(int i=min(n,m);i<=max(n,m);i++){
            if(isPrime(i)) sum+=i;
        }
        return sum;
    }
};