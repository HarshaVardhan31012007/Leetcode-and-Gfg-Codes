class Solution {
public:
    bool checkp(string &ans,int s,int e){
        while(s<=e){

            if(ans[s]!=ans[e]){
            return false;
            }
            else{
                s++;
                e--;
            }

        }

        return true;

    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==s[j]){
                j--;
            }
            else{
                bool a=checkp(s,i+1,j);
                bool b=checkp(s,i,j-1);
                cout<<a<<b<<endl;
                bool c=a||b;
                return c;
            }
        }
        return true;
    }
};