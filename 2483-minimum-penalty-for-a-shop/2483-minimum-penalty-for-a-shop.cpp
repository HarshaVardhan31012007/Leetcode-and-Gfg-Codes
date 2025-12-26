class Solution {
public:
    int bestClosingTime(string customers) {
        // int n=customers.size();
        // vector<int>p(n,0);
        // p[0]=(customers[0]=='Y'?0:1);
        // for(int i=1;i<n;i++){
        //    p[i]=(p[i-1]+(customers[i]=='Y'?0:1));
        // }
        // int ans=INT_MAX;
        // int mini=INT_MAX;
        // int tclose=n-p[n-1];
        // for(int i=0;i<=n;i++){
        //    int cclose=tclose-(i>0?(i-p[i-1]):0);
        //    int bopen=(i>0?p[i-1]:0);
        //    int curr=bopen+cclose;
        //    if(curr<mini){
        //       mini=curr;
        //       ans=i;
        //    }
        // }
        // return ans;



        int n=customers.size();
        int ans=-1;
        int mini=INT_MAX;
        int open=0;
        for(int i=0;i<=n;i++){
           int curr=2*open+n-i;
           if(curr<mini){
              mini=curr;
              ans=i;
           }
           open+=(customers[i]=='Y'?0:1);
        }
        return ans;
    }
};