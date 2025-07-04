class Solution {
public:
    //Brute

    // void func(string &s){
    //   int n=s.length();
    //   for(int i=0;i<n;i++){
    //     if(s[i]=='z')
    //     s+='a';
    //     else
    //     s+=s[i]+1;
    //   }  
    // }
    // char kthCharacter(long long k, vector<int>& operations) {
    //     string s="a";
    //     for(auto &operation:operations){
    //         if(s.length()>=k) break;
    //         if(operation==0)
    //         s=s+s;
    //         else
    //         func(s);
    //     }
    //     return s[k-1];
    // }


    char kthCharacter(long long k, vector<int>& operations) {
       int count=0;
       while(k!=1){
        long long int val=ceil(log2(k));
        if(operations[val-1]==1) count++;
        k=k-(long long)pow(2,val-1);
       }
       return 'a'+(count%26);

       
    }
};