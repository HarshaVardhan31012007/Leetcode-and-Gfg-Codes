class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            s+=(i+'0');
        }
        if(k==1) return s;
        k--;
        while(next_permutation(s.begin(),s.end())){
            if(k==1) return s;
            k--;
        }
        return "";
    }
};