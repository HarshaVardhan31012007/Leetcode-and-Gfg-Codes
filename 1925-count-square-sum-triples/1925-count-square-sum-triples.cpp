class Solution {
public:
    int countTriples(int n) {
        // int ans=0;
        // for(double i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         double k=hypot(i,j);
        //         if(floor(k)==k&&k>=1&&k<=n){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        int ans=0;
        for(double i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                double k=hypot(i,j);
                if((int)k==k&&k>=1&&k<=n){
                    ans++;
                }
            }
        }
        return ans;
    }
};