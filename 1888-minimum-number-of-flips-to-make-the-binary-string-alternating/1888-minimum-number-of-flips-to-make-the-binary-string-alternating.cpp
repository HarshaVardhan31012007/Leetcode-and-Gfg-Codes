class Solution {
public:
    // int minFlips(string s) {
    //     int n=s.length();
    //     s=s+s;//imp to get all states after applying type1
    //     //in s // all are susbtrings that can be get by sliding window
    //     int ans=0;
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         if(i&1){
    //             if(s[i]=='0') cnt++;
    //         }
    //         else{
    //             if(s[i]=='1') cnt++;
    //         }
    //     }
    //     ans=min(cnt,n-cnt);
    //     int i=0;
    //     for(int j=n;j<2*n;j++){
    //         //removal
    //         if(i&1){
    //             if(s[i]=='0') cnt--;
    //         }
    //         else{
    //             if(s[i]=='1') cnt--;
    //         }
    //         i++;
    //         //addition
    //         if(j&1){
    //             if(s[j]=='0') cnt++;
    //         }
    //         else{
    //             if(s[j]=='1') cnt++;
    //         }
    //         //compute ans
    //         ans=min(ans,min(cnt,n-cnt));
    //     }
    //     return ans;
    // }



    int minFlips(string s) {
        int n=s.length();
        //s=s+s is imaginary can be get i=n to 2*n by moduleo operations
        //imp to get all states after applying type1
        //in s // all are susbtrings that can be get by sliding window
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='0') cnt++;
            }
            else{
                if(s[i]=='1') cnt++;
            }
        }
        ans=min(cnt,n-cnt);
        int i=0;
        for(int j=n;j<2*n;j++){
            //removal
            if(i&1){
                if(s[i]=='0') cnt--;
            }
            else{
                if(s[i]=='1') cnt--;
            }
            i++;
            //addition
            if(j&1){
                if(s[j%n]=='0') cnt++;
            }
            else{
                if(s[j%n]=='1') cnt++;
            }
            //compute ans
            ans=min(ans,min(cnt,n-cnt));
        }
        return ans;
    }
};