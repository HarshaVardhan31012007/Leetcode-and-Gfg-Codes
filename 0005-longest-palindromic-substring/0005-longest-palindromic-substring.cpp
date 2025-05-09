class Solution {
public:
    bool checkPalindrome(string &k){
        int i=0;
        int j=k.length()-1;
        while(i<j){
            if(k[i]==k[j]){
                i++;j--;
            }
            else
            return 0;
        }
        return 1;
    }
    string longestPalindrome(string s) {
        int maxi=INT_MIN;
        string ans="";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                string k=s.substr(i,j-i+1);
                 if(checkPalindrome(k)){
                 maxi=max(maxi,j-i+1);
                 if(maxi==j-i+1)
                 ans=k;
                 }
            }
        }
        return ans;
    }
};