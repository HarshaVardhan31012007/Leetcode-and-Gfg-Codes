class Solution {
public:
    int minimumDeletions(string s) {
        // int n=s.length();
        // vector<int>b_count(n+1,0);
        // for(int i=n-1;i>=0;i--){
        //     b_count[i]=b_count[i+1]+(s[i]=='b'?1:0);
        // }
        // int a_count=0;
        // int seq=INT_MIN;
        // for(int i=0;i<n;i++){
        //     a_count+=(s[i]=='a'?1:0);
        //     seq=max(seq,a_count+b_count[i]);
        // }
        // return n-seq;



        int n=s.length();
        vector<int>a_count(n+1,0);
        for(int i=n-1;i>=0;i--){
            a_count[i]=a_count[i+1]+(i+1<n?(s[i+1]=='a'?1:0):0);
        }
        int b_count=0;
        int del=INT_MAX;
        for(int i=0;i<n;i++){
            del=min(del,a_count[i]+b_count);
            b_count+=(s[i]=='b'?1:0);
        }
        return del;
    }
};