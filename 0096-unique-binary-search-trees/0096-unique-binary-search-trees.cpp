class Solution {
public:
    int solve(int s,int e){
        if(s>=e) return 1;
        int count=0;
        for(int i=s;i<=e;i++){
          int l=solve(s,i-1);
          int r=solve(i+1,e);
          count+=l*r;
        }
        return count;
    }
    int numTrees(int n) {
        //method 1
        // if(n==0||n==1)
        // return  1;
        // int ans=0;
        // for(int i=0;i<n;i++){
        //      ans+=numTrees(i)*numTrees(n-i-1);
        // }
        // return ans;

        //Method 2 //dp

        // vector<int>result(n+1,0);
        // result[0]=result[1]=1;
        // for(int i=2;i<=n;i++){
        //     for(int j=0;j<i;j++){
        //         result[i]+=result[j]*result[i-j-1];
        //     }
        // }
        // return result[n];


        //method 3
        return solve(1,n);
    }
};