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
    //    int count=0;
    //    while(k!=1){//k>1
    //     long long int val=ceil(log2(k));
    //     if(operations[val-1]==1) count++;
    //     k=k-(long long)pow(2,val-1);// if k=8 then val=3 
    //     //then pow(2,val-1)=4 8%4==0 so dont use modulo use subtraction
    //    }
    //    return 'a'+(count%26);


       
       int count=0;
       while(k!=1){
        long long int val=floor(log2(k));
        if((int)log2(k)==log2(k)){
            if(operations[val-1]==1) count++;// for k=16 val=4 here pow(2,val-1) not p
            //not pow(2,val)
            k=k-(long long)pow(2,val-1);
        } 
        else {
        if(operations[val]==1) count++;
        k=k-(long long)pow(2,val);
        }
       }
       return 'a'+(count%26);
    }
};