class Solution {
public:
    bool checkValidString(string s) {
        int mini=0;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }
            else if(s[i]==')'){
                mini--;
                maxi--;
            }
            else{
                mini=max(0,mini-1);
                maxi=maxi+1;
            }
            mini=max(0,mini);
            if(maxi<0) return false;
        }
        if(0>=mini){
            return true;
        }
        return false;
    }
};