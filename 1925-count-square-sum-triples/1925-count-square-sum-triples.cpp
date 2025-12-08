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


        // int ans=0;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         int k=(int)sqrt(i*i+j*j*1.0);//k is always greater than or equal to 1
        //         if(k<=n&&(k*k)==(i*i+j*j)){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;



        // int ans=0;
        // for(int i=1;i<=n;i++){
        //     for(int j=i+1;j<=n;j++){
        //         int k=(int)sqrt(i*i+j*j*1.0);//k is always greater than or equal to 1
        //         if(k<=n&&(k*k)==(i*i+j*j)){
        //             ans+=2;//a2+b2 is same as b2+a2
        //         }
        //     }
        // }
        // return ans;



        int ans=0;
        for(int c=1;c<=n;c++){
            int target=c*c;
            int s=1;
            int e=c-1;//as it is c2+k2>=c2 min k is 1
            while(s<=e){
                if(s*s+e*e==target){
                   ans+=2;
                   s++;
                   e--;
                }
                else if(s*s+e*e<target){
                    s++;
                }
                else
                e--;
            }
        }
        return ans;
    }
};