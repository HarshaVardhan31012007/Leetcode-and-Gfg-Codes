class Solution {
public:
    int numTrees(int n) {
        // if(n==0||n==1)
        // return  1;
        // int ans=0;
        // for(int i=0;i<n;i++){
        //      ans+=numTrees(i)*numTrees(n-i-1);
        // }
        // return ans;


        vector<int>result(n+1,0);
        result[0]=result[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                result[i]+=result[j]*result[i-j-1];
            }
        }
        return result[n];
    }
};