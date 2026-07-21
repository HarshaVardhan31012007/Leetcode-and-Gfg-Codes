// class Solution {
// public:
//     int maxActiveSectionsAfterTrade(string s) {
//         int n=s.length();
//         int pzero=-1;
//         int maxi=0;
//         int active=0;
//         for(int i=0;i<n;){
//             if(s[i]=='0'){
//                 if(pzero!=-1&&pzero<i-1){
//                     int c=0;
//                     int j=pzero;
//                     while(j>=0&&s[j]=='0'){
//                         j--;c++;
//                     }
//                     while(i<n&&s[i]=='0'){
//                         c++;i++;
//                     }
//                     pzero=i-1;
//                     maxi=max(maxi,c);
//                 }
//                 else
//                 pzero=i++;
//             }
//             else{
//                 active++;
//                 i++;
//             }
//         }
//         return maxi+active;
//     }
// };



class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int pzero=-1;
        int pone=-1;
        int maxi=0;
        int active=0;
        for(int i=0;i<n;){
            if(s[i]=='0'){
                if(pzero!=-1&&pzero<i-1){
                    int c=pzero-pone;
                    pone=i-1;
                    while(i<n&&s[i]=='0'){
                        c++;i++;
                    }
                    pzero=i-1;
                    maxi=max(maxi,c);
                }
                else
                pzero=i++;
            }
            else{
                active++;
                if(pzero==-1)
                pone=i;
                i++;
            }
        }
        return maxi+active;
    }
};