class Solution {
public:
    // bool isprime(int n){
    //     if(n<=1) return false;
    //     for(int i=2;i<=sqrt(n);i++){
    //         if(n%i==0)
    //             return false;
    //     }
    //     return true;
    // }
    // bool completePrime(int num) {
    //     string s=to_string(num);
    //     string temp="";
    //     for(int i=0;i<s.length();i++){
    //         temp+=s[i];
    //         int n=stoi(temp);
    //         if(!isprime(n))
    //             return false;
    //     }
    //     temp="";
    //     for(int i=s.length()-1;i>=0;i--){
    //          temp=s[i]+temp;
    //          int n=stoi(temp);
    //          if(!isprime(n))
    //             return false;
    //     }
    //     return true;
    // }



    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string s=to_string(num);
        for(int i=0;i<s.length();i++){
            int n=stoi(s.substr(0,i+1));
            if(!isprime(n))
                return false;
        }
        for(int i=s.length()-1;i>=0;i--){
             int n=stoi(s.substr(i,s.length()-i));
             if(!isprime(n))
                return false;
        }
        return true;
    }
};