class Solution {
public:
    // bool isBalanced(int n){
    //     vector<int>digits(10,0);
    //     int k=n;
    //     while(k){
    //         digits[k%10]++;
    //         k=k/10;
    //     }
    //     for(int i=0;i<10;i++){
    //         if(digits[i]!=0&&digits[i]!=i)
    //         return 0;
    //     }
    //     return 1;
    // }
    // int nextBeautifulNumber(int n) {
    //     for(int i=n+1;i<=1224444;i++){
    //          if(isBalanced(i))
    //          return i;
    //     }
    //     return -1;
    // }

    

    // bool isBalanced(int n){
    //     vector<int>digits(10,0);
    //     int k=n;
    //     while(k){
    //         digits[k%10]++;
    //         k=k/10;
    //     }
    //     for(int i=0;i<10;i++){
    //         if(digits[i]!=0&&digits[i]!=i)
    //         return 0;
    //     }
    //     return 1;
    // }
    // int nextBeautifulNumber(int n) {
    //     for(int i=n+1;i<=1224444;i++){
    //          if(isBalanced(i))
    //          return i;
    //     }
    //     return -1;
    // }



    int solve(int n,vector<int>&digits,int curr,int remd){
        if(remd==0){
            for(int i=1;i<=9;i++){
                if(digits[i]!=i&&digits[i]!=0)
                return 0;
            }
            return curr>n?curr:0;
        }
        int result=0;
        for(int i=1;i<=9;i++){
            if(digits[i]>0&&digits[i]<=remd){
                digits[i]--;
                result=solve(n,digits,curr*10+i,remd-1);
                if(result!=0)
                return result;
                digits[i]++;
            }
        }
        return result;
    }
    int nextBeautifulNumber(int n) {
       vector<int>digits{0,1,2,3,4,5,6,7,8,9};
    //    int ndigits=to_string(n).length();
       int k=n;
       int ndigits=0;
       while(k){
          ndigits++;
          k=k/10;
       }
       int ans=solve(n,digits,0,ndigits);
       if(ans==0)
       ans=solve(n,digits,0,ndigits+1);
       return ans;
    }
};