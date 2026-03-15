// class Fancy {
// public:
//     vector<long long>ans;
//     const int mod=1e9+7;
//     Fancy() {
        
//     }
    
//     void append(int val) {
//         ans.push_back(val);
//     }
    
//     void addAll(int inc) {
//         for(auto &each:ans)
//         each=(each+inc)%mod;
//     }
    
//     void multAll(int m) {
//         for(auto &each:ans)
//         each=(each*m)%mod;
//     }
    
//     int getIndex(int idx) {
//         if(idx<ans.size())
//         return (ans[idx])%mod;
//         else
//         return -1;
//     }
// };



class Fancy {
public:
    vector<long long>numbers;
    const int mod=1e9+7;
    long long add,mul;
    Fancy() {
        add=0;
        mul=1;
    }
    long long getPower(long long a,long long b){
        long long ans=1;
        while(b!=0){
            if(b&1)
            ans=(ans*a)%mod;
            a=(a*a)%mod;
            b=b>>1;
        }
        return ans;
    }
    long long modInverse(long long a){
        return getPower(a,mod-2);
    }
    void append(int val) {
        long long curr=((val-add+mod)%mod*modInverse(mul)%mod)%mod;
        numbers.push_back(curr);
    }
    
    void addAll(int inc) {
        add=(add+inc)%mod;
    }
    
    void multAll(int m) {
        mul=(mul*m)%mod;
        add=(add*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=numbers.size()) return -1;
        long long curr=numbers[idx];
        curr=((curr*mul)%mod+add)%mod;
        return (int)curr;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */