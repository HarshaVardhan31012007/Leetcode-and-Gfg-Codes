class Solution {
public:
    int binaryGap(int n) {
          int num=n;
          int prev=-1;
          int ans=0;int c=0;
          while(num>0){
            int bit=num%2;
            if(bit==1){
                if(prev!=-1)
                   ans=max(ans,c-prev);
                prev=c;
            }
            c++;
            num=num/2;
          }
          return ans;
    }
};