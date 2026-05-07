class Solution {
public:
    vector<bool>isprime;
    int sumOfPrimesInRange(int n) {
        if(isprime.empty()){
            cout<<n<<endl;
            isprime.assign(1001,1);
            isprime[0]=0;isprime[1]=0;
            for(int i=2;i*i<=1000;i++){
                for(int j=i*i;j<=1000;j+=i){
                    isprime[j]=0;
                }
            }
        }
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int m=stoi(s);
        int l=min(m,n);
        int r=max(m,n);
        int sum=0;
        for(int i=l;i<=r;i++){
            if(isprime[i]){
                sum+=i;
            }
        }
        return sum;
    }
};