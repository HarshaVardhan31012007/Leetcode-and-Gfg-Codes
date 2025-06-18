class Solution {
public:
    // bool checkpalindrome(string &temp,int i,int j){
    //     int i=0;int j=temp.size()-1;
    //     while(i<j){
    //         if(temp[i]!=temp[j])
    //         return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // bool validPalindrome(string s) {
    //     if(checkpalindrome(s)) return true;
    //     for(int i=0;i<s.size();i++){
    //         string temp=s;
    //         for(int i=0;i<s.size();i++){
    //             temp.erase(i,1);
    //             if(checkpalindrome(temp)) return true;
    //             temp=s;
    //         }
    //     }
    //     return false;
    // }


    bool solve(string &s,int i,int j,int count){
        if(count>1) return false;
        if(i>=j) return true;
        if(s[i]==s[j])
        return solve(s,i+1,j-1,count);
        else
        return solve(s,i,j-1,count+1)||solve(s,i+1,j,count+1);
    }
    bool validPalindrome(string s) {
      int i=0;
      int j=s.length()-1;
      return solve(s,i,j,0);
    }

   
    // bool checkp(string &temp,int i,int j){
    //     while(i<j){
    //         if(temp[i]!=temp[j])
    //         return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // bool validPalindrome(string s) {
    //   int i=0;
    //   int j=s.length()-1;
    //    while(i<j){
    //     if(s[i]==s[j]){
    //         i++;
    //         j--;
    //     }
    //     else{
    //         return checkp(s,i+1,j)||checkp(s,i,j-1);
    //     }
    //    }
    //    return true;
    // }
};