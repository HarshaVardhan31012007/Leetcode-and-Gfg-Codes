class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int arr[256]={0};
       int brr[256]={0};
       for(int i=0;i<s.length();i++){
         if(!arr[s[i]]&&!brr[t[i]]){
            arr[s[i]]=t[i];
            brr[t[i]]=s[i];
         }
         else{
            if(arr[s[i]]!=t[i])
            return false;
         }
       }
       return true;
    }
};