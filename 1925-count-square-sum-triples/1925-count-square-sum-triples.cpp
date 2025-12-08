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

        // int ans=0;
        // for(double i=1;i<=n;i++){
        //     for(double j=1;j<=n;j++){
        //         double k=hypot(i,j);
        //         if((int)k==k&&k>=1&&k<=n){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;



        // int ans=0;
        // for(double i=1;i<=n;i++){
        //     for(double j=1;j<=n;j++){
        //         double k=sqrt(i*i+j*j*1.0);
        //         if((int)k==k&&k>=1&&k<=n){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;


        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int k=(int)sqrt(i*i+j*j*1.0);//k is always greater than or equal to 1
                if(k<=n&&(k*k)==(i*i+j*j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};