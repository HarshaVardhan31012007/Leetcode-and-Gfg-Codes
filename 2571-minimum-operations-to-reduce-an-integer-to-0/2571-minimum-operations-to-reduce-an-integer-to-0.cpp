class Solution {
public:
    int minOperations(int n) {
        vector<int>bits(32,0);
        for(int i=31;i>=0;i--){
            if((n>>i)&1) bits[i]=1;
        }
        int prev=0;int c=0;
        int ans=0;
        for(int i=0;i<32;i++){
            if(prev==1){
                if(bits[i])
                c++;
                else{
                   if(c>=2){
                      prev=1;
                      c=1;
                   }
                   else{
                     prev=0;
                     c=0;
                   }
                   ans+=1;
                }
            }
            else{
                if(bits[i]){
                    c++;
                    prev=1;
                }
            }
        }
        if(c>=2){
            ans+=2;
        }
        else if(c==1){
            ans+=1;
        }
        return ans;
    }
};