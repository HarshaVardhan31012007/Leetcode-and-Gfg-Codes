//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<bool>sieve(int n){
        
      vector<bool>s(n+1,true);
      s[0]=s[1]=false;
      for(int i=2;i<=sqrt(n);i++){

        for(int j=i*i;j<=n;j+=i)

            s[j]=false;

      }
      
      return s;
      
      }
    
    long long primeProduct(long long L, long long R){
        
    vector<bool>ss(R-L+1,true);
    
    if(L==0){
        ss[0]=ss[1]=false;
    }
    if(L==1)
    ss[0]=false;


    vector<int>baseprimes;
    vector<bool>s=sieve(sqrt(R));
    for(int i=0;i<s.size();i++){
        if(s[i])
        baseprimes.push_back(i);
    }

    
    for(auto prime:baseprimes){

        int first_mul=(L/prime)*prime;
        if(first_mul<L)
        first_mul+=prime;
        int j=max(first_mul,prime*prime);
        while(j<=R){
          ss[j-L]=false;
          j=j+prime;
        }

    }
    
     long long a=pow(10,9)+7;
    long long  product=1;
    for( int i=0;i<ss.size();i++){
         if(ss[i])
         product=(product*(L+i))%a;
    }
    

        return product%a;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends