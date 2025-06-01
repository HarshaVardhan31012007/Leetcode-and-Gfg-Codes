class Solution {
public:
    int strStr(string haystack, string needle) {
        // int j=0;
        // int i;
        // for(i=0;i<haystack.length();i++){
        //    if(haystack[i]==needle[j]){
        //    j++;
        //    if(j==needle.length()) break;
        //    }
        //    else{
        //      i=i-j;
        //      j=0;
        //    }
        // }
        // if(j<needle.length()) return -1;
        // return i-needle.length()+1;



        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<=n-m;i++){
            for(int j=0;j<m;j++){
                if(haystack[i+j]!=needle[j])
                break;
                if(j==m-1)
                return i;
            }
        }
        return -1;
    }
};