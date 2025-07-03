class Solution {
public:
    int count(int n){
        int count=0;
       while(n!=0){
        n=n&n-1;
        count++;
       }
       return count;
    }    
    //string s="a";
    char kthCharacter(int k) {
        // string s="a";
        // while(s.length()<k){
        //   int n=s.length();
        // for(int i=0;i<n;i++){
        //     int b=(s[i]-'a'+1)%26;
        //     s+=b+'a';
        // }
        // }
        // return s[k-1];


        // if(s.length()>=k)
        // return s[k-1];
        // int n=s.length();
        // for(int i=0;i<n;i++){
        //     int b=(s[i]-'a'+1)%26;
        //     s+=b+'a';
        // }
        // return kthCharacter(k);


        return 'a'+count(k-1);
    }
};