class Solution {
public:
    int numberOfSubstrings(string s) {
        // int ans=0;
        // for(int i=0;i<s.length();i++){
        //     int onec=0;int zeroc=0;
        //     for(int j=i;j<s.length();j++){
        //          if(s[j]=='0') zeroc++;
        //          if(s[j]=='1') onec++;
        //          if(onec>=zeroc*zeroc){
        //             ans++;
        //          }
        //     }
        // }
        // return ans;



        int ans=0;
        int n=s.length();
        vector<int>prefix(n,0);
        prefix[0]=(s[0]=='1')?1:0;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+((s[i]=='1')?1:0);
        }
        for(int i=0;i<n;i++){
            int onec=0;int zeroc=0;
            for(int j=i;j<n;j++){
                 onec=prefix[j]-((i>0)?prefix[i-1]:0);
                 zeroc=(j-i+1)-onec;
                 if(onec<zeroc*zeroc){
                    j+=(zeroc*zeroc-onec-1);
                 }
                 else if(onec==zeroc*zeroc){
                    ans++;
                 }
                 else if(onec>zeroc*zeroc){
                    ans++;
                    int diff=(int)sqrt(onec)-zeroc;
                    int nextj=j+diff;
                    if(nextj>=n){
                        ans+=(n-j-1);
                    }
                    else{
                        ans+=diff;
                    }
                    j=nextj;
                 }
            }
        }
        return ans;
    }
};