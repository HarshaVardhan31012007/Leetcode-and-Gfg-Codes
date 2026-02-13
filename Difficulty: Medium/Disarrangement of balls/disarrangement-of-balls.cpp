// User function Template for C++

class Solution {
  public:
    int arr[13]={0};
    int countDer(int n) {
        if(n==1) return 0;
        if(n==2) return 1;
        if(arr[n]!=0) return arr[n];
        return arr[n]=(n-1)*(countDer(n-1)+countDer(n-2));
    }
};