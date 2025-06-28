class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<bool>arr(n,1);
        arr[0]=arr[1]=0;
        for(int i=2;i<sqrt(n);i++){
            if(arr[i]){
            for(int j=i*i;j<n;j=j+i){
                arr[j]=0;
            }
            }
        }
        return accumulate(arr.begin(),arr.end(),0);
    }
};