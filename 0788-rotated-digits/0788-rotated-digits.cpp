class Solution {
public:
    int rotatedDigits(int n) {
        vector<int>v={0,1,5,-1,-1,2,9,-1,8,6};
        int ans=0;
        for(int i=1;i<=n;i++){
            int x=i;
            bool flag=true;
            bool same=true;
            while(x){
                int digit=x%10;
                if(v[digit]==-1){
                    flag=false;
                    break;
                }
                if(v[digit]!=digit)
                same=false;
                x=x/10;
            }
            if(!same&&flag) ans++; 
        }
        return ans;
    }
};